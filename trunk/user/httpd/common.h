/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef _COMMON_H_
#define _COMMON_H_

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef ABS
#define	ABS(a)			(((a) < 0)?-(a):(a))
#endif /* ABS */

#ifndef MIN
#define	MIN(a, b)		(((a) < (b))?(a):(b))
#endif /* MIN */

#ifndef MAX
#define	MAX(a, b)		(((a) > (b))?(a):(b))
#endif /* MAX */

typedef u_int64_t u64;
typedef u_int32_t u32;
typedef u_int16_t u16;
typedef u_int8_t u8;

/* --- System Core Services (系统核心服务) --- */
#define EVM_RESTART_FIREWALL		(1ULL <<  0) // 防火墙
#define EVM_RESTART_DHCPD		(1ULL <<  1) // DHCP服务
#define EVM_RESTART_RADV		(1ULL <<  2) // 路由通告
#define EVM_RESTART_DDNS		(1ULL <<  3) // 动态域名
#define EVM_RESTART_UPNP		(1ULL <<  4) // UPnP服务
#define EVM_RESTART_TIME		(1ULL <<  5) // 时间服务
#define EVM_RESTART_NTPC		(1ULL <<  6) // NTP客户端
#define EVM_RESTART_SYSLOG		(1ULL <<  7) // 系统日志
#define EVM_RESTART_NETFILTER		(1ULL <<  8) // 网络过滤
#define EVM_REAPPLY_VPNSVR		(1ULL <<  9) // 应用VPN服务
#define EVM_RESTART_VPNSVR		(1ULL << 10) // 重启VPN服务
#define EVM_RESTART_VPNCLI		(1ULL << 11) // 重启VPN客户端
#define EVM_RESTART_WIFI2		(1ULL << 12) // 2.4G WiFi
#define EVM_RESTART_WIFI5		(1ULL << 13) // 5G WiFi
#define EVM_RESTART_SWITCH_CFG		(1ULL << 14) // 交换机配置
#define EVM_RESTART_SWITCH_VLAN		(1ULL << 15) // 交换机VLAN
/* ID 16 (Lucky) is Third Party */
#define EVM_RESTART_LAN			(1ULL << 17) // 局域网LAN
#define EVM_RESTART_WAN			(1ULL << 18) // 广域网WAN
#define EVM_RESTART_IPV6		(1ULL << 19) // IPv6服务
#define EVM_RESTART_HTTPD		(1ULL << 20) // Web服务
#define EVM_RESTART_TELNETD		(1ULL << 21) // Telnet服务
#define EVM_RESTART_SSHD		(1ULL << 22) // SSH服务
#define EVM_RESTART_WINS		(1ULL << 23) // WINS服务
#define EVM_RESTART_LLTD		(1ULL << 24) // LLTD链路发现
#define EVM_RESTART_ADSC		(1ULL << 25) // ADSC服务
#define EVM_RESTART_IPTV		(1ULL << 26) // IPTV服务
#define EVM_RESTART_CROND		(1ULL << 27) // 计划任务
#define EVM_RESTART_SYSCTL		(1ULL << 28) // Sysctl参数
#define EVM_RESTART_TWEAKS		(1ULL << 29) // 系统调整
#define EVM_RESTART_WDG			(1ULL << 30) // 看门狗
#define EVM_RESTART_DI			(1ULL << 31) // 指示灯检测
#define EVM_RESTART_SPOOLER		(1ULL << 32) // 打印队列
#define EVM_RESTART_MODEM		(1ULL << 33) // 调制解调器
#define EVM_RESTART_HDDTUNE		(1ULL << 34) // 硬盘调整
#define EVM_RESTART_FTPD		(1ULL << 35) // FTP服务
#define EVM_RESTART_NMBD		(1ULL << 36) // NetBIOS服务
#define EVM_RESTART_SMBD		(1ULL << 37) // SMB共享(文件)
#define EVM_RESTART_NFSD		(1ULL << 38) // NFS服务

/* --- Third-Party Plugins (第三方扩展功能) --- */
#define EVM_RESTART_LUCKY		    (1ULL << 16) // [第三方] Lucky插件
#define EVM_RESTART_UUPLUGIN		(1ULL << 39) // [第三方] UU加速器 (原DMS)
#define EVM_RESTART_V2RAYA		(1ULL << 40) // [第三方] V2RayA (原iTunes)
#define EVM_RESTART_TRMD		(1ULL << 41) // [第三方] Transmission下载
#define EVM_RESTART_ARIA		(1ULL << 42) // [第三方] Aria2下载
#define EVM_RESTART_SCUT		(1ULL << 43) // [第三方] 华南理工认证
#define EVM_RESTART_TTYD		(1ULL << 44) // [第三方] 网页终端TTYD
#define EVM_RESTART_VLMCSD		(1ULL << 45) // [第三方] KMS激活服务
#define EVM_RESTART_IPERF3		(1ULL << 46) // [第三方] 带宽测试工具
#define EVM_RESTART_DNSFORWARDER	(1ULL << 47) // [第三方] DNS转发服务
#define EVM_RESTART_SHADOWSOCKS	(1ULL << 48) // [第三方] SS代理客户端
#define EVM_RESTART_SS_TUNNEL		(1ULL << 49) // [第三方] SS转发隧道
#define EVM_RESTART_MENTOHUST		(1ULL << 50) // [第三方] 锐捷认证客户端
#define EVM_RESTART_ADBYBY		    (1ULL << 51) // [第三方] Adbyby去广告
#define EVM_RESTART_ALIDDNS		    (1ULL << 52) // [第三方] 阿里DDNS动态域名
#define EVM_RESTART_FRP		    (1ULL << 53) // [第三方] FRP内网穿透
#define EVM_RESTART_WXSEND		    (1ULL << 54) // [第三方] 微信推送通知
#define EVM_RESTART_CLOUDFLARED		    (1ULL << 55) // [第三方] Cloudflared隧道
#define EVM_RESTART_SMARTDNS		    (1ULL << 56) // [第三方] SmartDNS防污染
#define EVM_RESTART_ADGUARDHOME		    (1ULL << 57) // [第三方] AdGuardHome去广告
#define EVM_RESTART_ZEROTIER		    (1ULL << 58) // [第三方] ZeroTier异地组网
#define EVM_RESTART_DDNSTO		    (1ULL << 59) // [第三方] DDNSTO内网穿透
#define EVM_RESTART_ALDRIVER		    (1ULL << 60) // [第三方] 阿里云盘挂载
#define EVM_RESTART_WIREGUARD		    (1ULL << 61) // [第三方] WireGuard异地组网
#define EVM_RESTART_SQM		    (1ULL << 62) // [第三方] SQM流量控制(QoS)

/* --- System Control Flags (系统控制标志) --- */
#define EVM_RESTART_REBOOT		(1ULL << 63) // [系统] 执行系统重启
#define EVM_BLOCK_UNSAFE		(1ULL << 65) /* [系统] 安全敏感标记 (大于64位，特殊用途) */


#define EVT_RESTART_FIREWALL		1
#define EVT_RESTART_DHCPD		1
#define EVT_RESTART_RADV		1
#define EVT_RESTART_DDNS		1
#define EVT_RESTART_UPNP		1
#define EVT_RESTART_TIME		2
#define EVT_RESTART_NTPC		1
#define EVT_RESTART_SYSLOG		1
#define EVT_RESTART_NETFILTER		1
#define EVT_REAPPLY_VPNSVR		1
#define EVT_RESTART_VPNSVR		2
#define EVT_RESTART_VPNCLI		2
#if defined (USE_RT3352_MII)
#define EVT_RESTART_WIFI2		5
#else
#define EVT_RESTART_WIFI2		3
#endif
#define EVT_RESTART_WIFI5		3
#define EVT_RESTART_SWITCH_CFG		3
#define EVT_RESTART_SWITCH_VLAN		3
#define EVT_RESTART_LAN			5
#define EVT_RESTART_WAN			5
#define EVT_RESTART_IPV6		3
#define EVT_RESTART_HTTPD		2
#define EVT_RESTART_TELNETD		1
#define EVT_RESTART_SSHD		1
#define EVT_RESTART_WINS		2
#define EVT_RESTART_LLTD		1
#define EVT_RESTART_ADSC		1
#define EVT_RESTART_CROND		1
#define EVT_RESTART_IPTV		1
#define EVT_RESTART_SYSCTL		1
#define EVT_RESTART_TWEAKS		1
#define EVT_RESTART_WDG			1
#define EVT_RESTART_DI			1
#define EVT_RESTART_SPOOLER		1
#define EVT_RESTART_MODEM		3
#define EVT_RESTART_HDDTUNE		1
#define EVT_RESTART_FTPD		1
#define EVT_RESTART_NMBD		2
#define EVT_RESTART_SMBD		2
#define EVT_RESTART_NFSD		2
#define EVT_RESTART_UUPLUGIN			2
#define EVT_RESTART_V2RAYA			2
#define EVT_RESTART_TRMD		3
#define EVT_RESTART_ARIA		3
#define EVT_RESTART_SCUT		1
#define EVT_RESTART_TTYD		1
#define EVT_RESTART_SMARTDNS      	1
#define EVT_RESTART_VLMCSD		1
#define EVT_RESTART_IPERF3		1
#define EVT_RESTART_SHADOWSOCKS	2
#define EVT_RESTART_ADBYBY	2
#define EVT_RESTART_ZEROTIER    2
#define EVT_RESTART_DDNSTO     	2
#define EVT_RESTART_ALDRIVER     	2
#define EVT_RESTART_WIREGUARD     	2
#define EVT_RESTART_SQM		2
#define EVT_RESTART_ALIDDNS	2
#define EVT_RESTART_FRP      		2
#define EVT_RESTART_SS_TUNNEL		2
#define EVT_RESTART_DNSFORWARDER	1
#define EVT_RESTART_MENTOHUST		2
#define EVT_RESTART_ADGUARDHOME      	1
#define EVT_RESTART_LUCKY		2
#define EVT_RESTART_WXSEND		2
#define EVT_RESTART_CLOUDFLARED		2
#define EVT_RESTART_REBOOT		40

struct variable
{
	const char *name;
	const char *longname;
	char **argv;
	u64 event_mask;
};

struct svcLink
{
	const char *serviceId;
	struct variable *variables;
};

struct evDesc
{
	u64 event_mask;
	u32 max_time;
	const char* notify_cmd;
	u64 event_unmask;
};

#define ARGV(args...) ((char *[]) { args, NULL })

/* API export for UPnP function */
int LookupServiceId(char *serviceId);
const char *GetServiceId(int sid);
struct variable *GetVariables(int sid);


#endif /* _COMMON_H_ */
