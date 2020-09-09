#ifndef __QL_UTILS_NET_H__
#define __QL_UTILS_NET_H__
#include <stdint.h>
#include <arpa/inet.h>


/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Get network interface name by interface index 
  @param[in] ifindex Interface index 
  @param[out] ifname_buf
  @param[in] ifname_buf_len
  @return
  0 - succeed \n
  -1 - error ocurred
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_net_get_ifname(int ifindex, char *ifname_buf, int ifname_buf_len);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Get network interface index by interface name
  @param[in] ifname Interface name 
  @param[out] p_index Interface index
  @return
  0 - succeed \n
  -1 - error ocurred
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_net_get_ifindex(const char *ifname, int *p_index);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Get the active flag word of the device, flags contains a bit mask of the following values: 
  IFF_UP            Interface is running.
  IFF_BROADCAST     Valid broadcast address set.
  IFF_DEBUG         Internal debugging flag.
  IFF_LOOPBACK      Interface is a loopback interface.
  IFF_POINTOPOINT   Interface is a point-to-point link.
  IFF_RUNNING       Resources allocated.
  IFF_NOARP         No arp protocol, L2 destination address not set.

  IFF_PROMISC       Interface is in promiscuous mode.
  IFF_NOTRAILERS    Avoid use of trailers.
  IFF_ALLMULTI      Receive all multicast packets.
  IFF_MASTER        Master of a load balancing bundle.
  IFF_SLAVE         Slave of a load balancing bundle.
  IFF_MULTICAST     Supports multicast
  IFF_PORTSEL       Is able to select media type via ifmap.
  IFF_AUTOMEDIA     Auto media selection active.
  IFF_DYNAMIC       The addresses are lost when the interface goes down.
  IFF_LOWER_UP      Driver signals L1 up (since Linux 2.6.17)
  IFF_DORMANT       Driver signals dormant (since Linux 2.6.17)
  IFF_ECHO          Echo sent packets (since Linux 2.6.25)
  @param[in] ifname Interface name 
  @param[out] p_flags
  @return
  0 - succeed \n
  -1 - error ocurred
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_net_get_ifflag(const char *ifname, uint32_t *p_flags);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Set the active flag word of the device, flags contains a bit mask of the following values:
  IFF_UP            Interface is running.
  IFF_BROADCAST     Valid broadcast address set.
  IFF_DEBUG         Internal debugging flag.
  IFF_LOOPBACK      Interface is a loopback interface.
  IFF_POINTOPOINT   Interface is a point-to-point link.
  IFF_RUNNING       Resources allocated.
  IFF_NOARP         No arp protocol, L2 destination address not set.

  IFF_PROMISC       Interface is in promiscuous mode.
  IFF_NOTRAILERS    Avoid use of trailers.
  IFF_ALLMULTI      Receive all multicast packets.
  IFF_MASTER        Master of a load balancing bundle.
  IFF_SLAVE         Slave of a load balancing bundle.
  IFF_MULTICAST     Supports multicast
  IFF_PORTSEL       Is able to select media type via ifmap.
  IFF_AUTOMEDIA     Auto media selection active.
  IFF_DYNAMIC       The addresses are lost when the interface goes down.
  IFF_LOWER_UP      Driver signals L1 up (since Linux 2.6.17)
  IFF_DORMANT       Driver signals dormant (since Linux 2.6.17)
  IFF_ECHO          Echo sent packets (since Linux 2.6.25)
  @param[in] ifname Interface name 
  @param[in] flags
  @return
  0 - succeed \n
  -1 - error ocurred
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_net_set_ifflag(const char *ifname, uint32_t flags);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Network interface up, same as ifconfig xxx up 
  @param[in] ifname Interface name 
  @param[out] p_index Interface index
  @return
  0 - succeed \n
  -1 - error ocurred
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_net_set_ifup(const char *ifname);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Network interface down, same as ifconfig xxx down
  @param[in] ifname Interface name 
  @param[out] p_index Interface index
  @return
  0 - succeed \n
  -1 - error ocurred
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_net_set_ifdown(const char *ifname);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Set network interface mtu
  @param[in] ifname Interface name 
  @param[out] p_mtu Return interface mtu 
  @return
  0 - succeed \n
  -1 - error ocurred
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_net_set_ifmtu(const char *ifname, int mtu);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Get network interface mtu
  @param[in] ifname Interface name 
  @param[out] p_mtu Return interface mtu 
  @return
  0 - succeed \n
  -1 - error ocurred
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_net_get_ifmtu(const char *ifname, int *p_mtu);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Set network interface MAC address by interface name 
  @param[in] ifindex Interface index 
  @param[in] mac_buf
  @param[in] ifname_buf_len
  @return
  0 - succeed \n
  -1 - error ocurred
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_net_set_ifmac(const char *ifname, uint8_t *mac_buf, int mac_buf_len);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Get network interface MAC address by interface name 
  @param[in] ifindex Interface index 
  @param[out] mac_buf
  @param[in] mac_buf_len
  @return
  0 - succeed \n
  -1 - error ocurred
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_net_get_ifmac(const char *ifname, uint8_t *mac_buf, int mac_buf_len);



/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Convert IPV4 address to string 
  @param[in] paddr 
  @param[out] str_buf
  @param[in] str_buf_len
  @return
  0 - succeed \n
  -1 - error ocurred
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_net_ipstr(struct in_addr *paddr, char *str_buf, int str_buf_len);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Convert string to IPV4 address 
  @param[in]  str 
  @param[out] paddr 
  @return
  0 - succeed \n
  -1 - error ocurred
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_net_strip(const char *str, struct in_addr *paddr);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Convert IPV6 address to string 
  @param[in] paddr 
  @param[out] str_buf
  @param[in] str_buf_len
  @return
  0 - succeed \n
  -1 - error ocurred
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_net_ip6str(struct in6_addr *paddr, char *str_buf, int str_buf_len);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Convert mac address to string 
  @param[in] paddr 
  @param[out] str_buf
  @param[in] str_buf_len
  @return
  0 - succeed \n
  -1 - error ocurred
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_net_macstr(uint8_t *mac, int mac_len, char *str_buf, int str_buf_len);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Convert mac address to string 
  @param[in] paddr 
  @param[out] str_buf
  @param[in] str_buf_len
  @return
  0 - succeed \n
  -1 - error ocurred
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_net_strmac(const char *str_buf, uint8_t *mac, int mac_len);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Create a local socket server 
  @param[in] ipc_file
  @return
  0 - succeed \n
  -1 - error ocurred
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_net_ipc_server(const char *ipc_file);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Create a local socket client and connect to the server
  @param[in] ipc_file
  @return
  0 - succeed \n
  -1 - error ocurred
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_net_ipc_client(const char *ipc_file);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Send a message on a socket 
  @param[in] fd
  @param[in] msg_buf
  @param[in] msg_len
  @return
  0 - succeed \n
  -1 - error ocurred
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_net_send(int fd, void *msg_buf, int msg_len);

/*-----------------------------------------------------------------------------------------------*/
/**
  @brief Recv a message from a socket 
  @param[in] fd
  @param[out] msg_buf
  @param[in] msg_len
  @return
  >=0 - the number of bytes received \n
  -1 - error ocurred
  */
/*-----------------------------------------------------------------------------------------------*/
int qlu_net_recv(int fd, void *msg_buf, int msg_len);


#endif

