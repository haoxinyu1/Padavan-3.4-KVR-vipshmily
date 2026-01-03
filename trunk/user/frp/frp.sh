#!/bin/sh
frpc_enable=`nvram get frpc_enable`
frps_enable=`nvram get frps_enable`
http_username=`nvram get http_username`

check_frp () 
{
	check_net
	result_net=$?
	if [ "$result_net" = "1" ] ;then
		if [ -z "`pidof frpc`" ] && [ "$frpc_enable" = "1" ];then
			frp_start
		fi
		if [ -z "`pidof frps`" ] && [ "$frps_enable" = "1" ];then
			frp_start
		fi
	fi
}

check_net() 
{
	/bin/ping -c 3 223.5.5.5 -w 5 >/dev/null 2>&1
	if [ "$?" == "0" ]; then
		return 1
	else
		return 2
		logger -t "frp" "检测到互联网未能成功访问,稍后再尝试启动frp"
	fi
}

frp_start () 
{
    frp_bin_dir="/tmp/frp_bin"
    mkdir -p "$frp_bin_dir"
    export PATH="$frp_bin_dir:$PATH"

    if [ ! -x "$frp_bin_dir/frpc" ] || [ ! -x "$frp_bin_dir/frps" ]; then
        logger -t "frp" "FRP 二进制文件缺失，开始下载..."
        frp_url=`nvram get frp_url`
        save_path="/tmp/frp.tar.gz"
        
        dl_success=0
        if [ -n "$frp_url" ]; then
            logger -t "frp" "使用自定义地址下载: $frp_url"
            curl -k -s -o "$save_path" --connect-timeout 10 --retry 3 "$frp_url" && dl_success=1
        fi

        if [ "$dl_success" = "0" ]; then
            def_url="https://github.com/fatedier/frp/releases/download/v0.57.0/frp_0.57.0_linux_mipsle.tar.gz"
            logger -t "frp" "使用默认地址下载: $def_url"
            curl -k -s -o "$save_path" --connect-timeout 10 --retry 3 "$def_url" && dl_success=1
        fi

        if [ "$dl_success" = "1" ]; then
            logger -t "frp" "下载成功，正在解压..."
            tar -xzf "$save_path" -C "/tmp"
            # 移动解压后的文件到 bin 目录 (假设解压出的是 frp_0.57.0_linux_mipsle 目录)
            find /tmp -name "frpc" -type f -exec mv {} "$frp_bin_dir/" \;
            find /tmp -name "frps" -type f -exec mv {} "$frp_bin_dir/" \;
            chmod +x "$frp_bin_dir/frpc"
            chmod +x "$frp_bin_dir/frps"
            rm -f "$save_path"
            rm -rf /tmp/frp_*_linux_mipsle
        else
            logger -t "frp" "下载失败，请检查网络或自定义URL。"
        fi
    fi

	/etc/storage/frp_script.sh
	sed -i '/frp/d' /etc/storage/cron/crontabs/$http_username
	cat >> /etc/storage/cron/crontabs/$http_username << EOF
*/1 * * * * /bin/sh /usr/bin/frp.sh C >/dev/null 2>&1
EOF
	[ ! -z "`pidof frpc`" ] && logger -t "frp" "frpc启动成功"
	[ ! -z "`pidof frps`" ] && logger -t "frp" "frps启动成功"
}

frp_close () 
{
	if [ "$frpc_enable" = "0" ]; then
		if [ ! -z "`pidof frpc`" ]; then
		killall -9 frpc frp_script.sh
		[ -z "`pidof frpc`" ] && logger -t "frp" "已停止 frpc"
	    fi
	fi
	if [ "$frps_enable" = "0" ]; then
		if [ ! -z "`pidof frps`" ]; then
		killall -9 frps frp_script.sh
		[ -z "`pidof frps`" ] && logger -t "frp" "已停止 frps"
	    fi
	fi
	if [ "$frpc_enable" = "0" ] && [ "$frps_enable" = "0" ]; then
	sed -i '/frp/d' /etc/storage/cron/crontabs/$http_username
    fi
}


case $1 in
start)
	frp_start
	;;
stop)
	frp_close
	;;
C)
	check_frp
	;;
esac
