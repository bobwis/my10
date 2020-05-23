package CodeGenerator;

import java.util.*;
import com.ifx.davex.appjetinteract.App2JetInterface;

public class eth004_confh_template
{
  protected static String nl;
  public static synchronized eth004_confh_template create(String lineSeparator)
  {
    nl = lineSeparator;
    eth004_confh_template result = new eth004_confh_template();
    nl = null;
    return result;
  }

  public final String NL = nl == null ? (System.getProperties().getProperty("line.separator")) : nl;
  protected final String TEXT_1 = "/*CODE_BLOCK_BEGIN[ETH004_Conf.h]*/" + NL + " /******************************************************************************" + NL + " *" + NL + " * Copyright (C) 2011 Infineon Technologies AG. All rights reserved." + NL + " *" + NL + " * Infineon Technologies AG (Infineon) is supplying this software for use with " + NL + " * Infineon's microcontrollers.  " + NL + " * This file can be freely distributed within development tools that are " + NL + " * supporting such microcontrollers. " + NL + " *" + NL + " * THIS SOFTWARE IS PROVIDED \"AS IS\".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED" + NL + " * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF" + NL + " * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE." + NL + " * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, " + NL + " * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER." + NL + " *" + NL + "********************************************************************************" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "**                                                                            **" + NL + "** PLATFORM : Infineon XMC4000 Series                                         **" + NL + "**                                                                            **" + NL + "** COMPILER : Compiler Independent                                            **" + NL + "**                                                                            **" + NL + "** AUTHOR : DAVE App Developer                                                **" + NL + "**                                                                            **" + NL + "** MAY BE CHANGED BY USER [Yes/No]: Yes                                       **" + NL + "**                                                                            **" + NL + "** MODIFICATION DATE : Sep 18, 2012                                           **" + NL + "**                                                                            **" + NL + "*******************************************************************************/" + NL + "/*******************************************************************************" + NL + "**                       Author(s) Identity                                   **" + NL + "********************************************************************************" + NL + "**                                                                            **" + NL + "** Initials     Name                                                          **" + NL + "** ---------------------------------------------------------------------------**" + NL + "** JJ           DAVE App Developer                                            **" + NL + "********************************************************************************";
  protected final String TEXT_2 = NL + " * @file   ETH004_Conf.h" + NL + " *" + NL + " * @App Version ETH004 <";
  protected final String TEXT_3 = ">" + NL + " *" + NL + " * @brief  Configuration file generated based on UI settings " + NL + " *         of ETH004 App" + NL + " *" + NL + " */ " + NL + " " + NL + " #ifndef ETH004_H_" + NL + " #define ETH004_H_" + NL + " " + NL + " #define NO_SYS                         1" + NL + " #define LWIP_NETCONN                   0" + NL + " #define LWIP_SOCKET                    0" + NL + " ";
  protected final String TEXT_4 = "   ";
  protected final String TEXT_5 = "  " + NL + "  /** For enabling DHCP  */" + NL + " #ifndef LWIP_DHCP" + NL + " #define LWIP_DHCP                      1" + NL + " #endif";
  protected final String TEXT_6 = " " + NL + " #ifndef LWIP_DHCP" + NL + " #define LWIP_DHCP                      0" + NL + " #endif";
  protected final String TEXT_7 = NL + " #ifndef MEM_SIZE" + NL + " #define MEM_SIZE                       ";
  protected final String TEXT_8 = NL + " #endif" + NL + "" + NL + " #ifndef IP_DEFAULT_TTL" + NL + " #define IP_DEFAULT_TTL                 ";
  protected final String TEXT_9 = NL + " #endif" + NL + "" + NL + " #ifndef LWIP_ICMP" + NL + " #define LWIP_ICMP                      ";
  protected final String TEXT_10 = NL + " #endif" + NL + "   " + NL + " #ifndef LWIP_BROADCAST_PING" + NL + " #define LWIP_BROADCAST_PING            ";
  protected final String TEXT_11 = NL + " #endif" + NL + " " + NL + " #ifndef LWIP_MULTICAST_PING\t" + NL + " #define LWIP_MULTICAST_PING            ";
  protected final String TEXT_12 = NL + " #endif" + NL + "  " + NL + " #ifndef LWIP_UDP" + NL + " #define LWIP_UDP                       ";
  protected final String TEXT_13 = NL + " #endif" + NL + "  " + NL + " #ifndef LWIP_TCP" + NL + " #define LWIP_TCP                       ";
  protected final String TEXT_14 = NL + " #endif" + NL + " " + NL + " #ifndef LWIP_DNS" + NL + " #define LWIP_DNS                       ";
  protected final String TEXT_15 = NL + " #endif" + NL + " " + NL + " #ifndef DNS_TABLE_SIZE" + NL + " #define DNS_TABLE_SIZE                 ";
  protected final String TEXT_16 = NL + " #endif" + NL + "" + NL + " #ifndef DNS_MAX_SERVERS" + NL + " #define DNS_MAX_SERVERS                ";
  protected final String TEXT_17 = NL + " #endif" + NL + "" + NL + " #ifndef DNS_SERVER_ADDRESS             " + NL + " #define DNS_SERVER_ADDRESS             inet_addr(\"";
  protected final String TEXT_18 = "\") " + NL + " #endif " + NL + "" + NL + " #ifndef LWIP_NETIF_HOSTNAME" + NL + " #define LWIP_NETIF_HOSTNAME            ";
  protected final String TEXT_19 = NL + " #endif" + NL + "" + NL + " #ifndef LWIP_NETIF_STATUS_CALLBACK" + NL + " #define LWIP_NETIF_STATUS_CALLBACK     ";
  protected final String TEXT_20 = NL + " #endif" + NL + "" + NL + " #ifndef LWIP_NETIF_LINK_CALLBACK" + NL + " #define LWIP_NETIF_LINK_CALLBACK       ";
  protected final String TEXT_21 = NL + " #endif" + NL + "" + NL + " #ifndef LWIP_IGMP" + NL + " #define LWIP_IGMP                      ";
  protected final String TEXT_22 = " " + NL + " #endif" + NL + " " + NL + " #ifndef LWIP_CHECKSUM_BY_HARDWARE" + NL + " #define LWIP_CHECKSUM_BY_HARDWARE      ";
  protected final String TEXT_23 = "   " + NL + " #endif " + NL + " ";
  protected final String TEXT_24 = " ";
  protected final String TEXT_25 = NL + " /* For Enabling SNMP by SNMP-APP*/" + NL + " #ifndef LWIP_SNMP" + NL + " #define LWIP_SNMP                     0 " + NL + " #endif" + NL + " " + NL + " /*For Enabling PPP by PPP-APP*/ " + NL + " #ifndef PPP_SUPPORT" + NL + " #define PPP_SUPPORT                   0" + NL + " #endif" + NL + " " + NL + " /*For Enabling PPP over Ethernet Support by PPP-APP*/" + NL + " #ifndef PPPOE_SUPPORT" + NL + " #define PPPOE_SUPPORT                 0" + NL + " #endif";
  protected final String TEXT_26 = NL + " /* For Enabling SNMP by SNMP-APP*/" + NL + " #ifndef LWIP_SNMP" + NL + " #define LWIP_SNMP                     1 " + NL + " #endif" + NL + " " + NL + " /*For Enabling PPP by PPP-APP*/ " + NL + " #ifndef PPP_SUPPORT" + NL + " #define PPP_SUPPORT                   0" + NL + " #endif" + NL + " " + NL + " /*For Enabling PPP over Ethernet Support by PPP-APP*/" + NL + " #ifndef PPPOE_SUPPORT" + NL + " #define PPPOE_SUPPORT                 0" + NL + " #endif";
  protected final String TEXT_27 = NL + " /* For Enabling SNMP by SNMP-APP*/" + NL + " #ifndef LWIP_SNMP" + NL + " #define LWIP_SNMP                     0 " + NL + " #endif" + NL + " " + NL + " /*For Enabling PPP by PPP-APP*/ " + NL + " #ifndef PPP_SUPPORT" + NL + " #define PPP_SUPPORT                   1" + NL + " #endif" + NL + " " + NL + " /*For Enabling PPP over Ethernet Support by PPP-APP*/" + NL + " #ifndef PPPOE_SUPPORT" + NL + " #define PPPOE_SUPPORT                 1" + NL + " #endif";
  protected final String TEXT_28 = NL + " " + NL + " #endif /* ETH004_H_ */  " + NL + "/*CODE_BLOCK_END*/" + NL + NL;
  protected final String TEXT_29 = NL;

  public String generate(Object argument)
  {
    final StringBuffer stringBuffer = new StringBuffer();
     App2JetInterface app = (App2JetInterface) argument; 
    stringBuffer.append(TEXT_1);
     String AppBaseuri1 = "app/eth004/";
    stringBuffer.append(TEXT_2);
    stringBuffer.append(app.getAppVersion(AppBaseuri1) );
    stringBuffer.append(TEXT_3);
     String AppBaseuri = "app/eth004/0";
     int Dhcp = app.getIntegerValue(AppBaseuri + "/eth004_ipconfig/" + 0); 
    stringBuffer.append(TEXT_4);
     if (Dhcp == 1) {
    stringBuffer.append(TEXT_5);
    }
  else if (Dhcp == 0)
 {
    stringBuffer.append(TEXT_6);
    } 
    stringBuffer.append(TEXT_7);
    stringBuffer.append(app.getIntegerValue(AppBaseuri  + "/eth004_mem_size"));
    stringBuffer.append(TEXT_8);
    stringBuffer.append(app.getIntegerValue(AppBaseuri  + "/eth004_ip_default_ttl"));
    stringBuffer.append(TEXT_9);
    stringBuffer.append(app.getIntegerValue(AppBaseuri  + "/eth004_lwip_icmp/" + 0));
    stringBuffer.append(TEXT_10);
    stringBuffer.append(app.getIntegerValue(AppBaseuri  + "/eth004_lwip_broadcast_ping/" + 0));
    stringBuffer.append(TEXT_11);
    stringBuffer.append(app.getIntegerValue(AppBaseuri  + "/eth004_lwip_multicast_ping/" + 0));
    stringBuffer.append(TEXT_12);
    stringBuffer.append(app.getIntegerValue(AppBaseuri  + "/eth004_lwip_udp/" + 0));
    stringBuffer.append(TEXT_13);
    stringBuffer.append(app.getIntegerValue(AppBaseuri  + "/eth004_lwip_tcp/" + 0));
    stringBuffer.append(TEXT_14);
    stringBuffer.append(app.getIntegerValue(AppBaseuri  + "/eth004_dns_enable/" + 0));
    stringBuffer.append(TEXT_15);
    stringBuffer.append(app.getIntegerValue(AppBaseuri  + "/eth004_dns_table_size"));
    stringBuffer.append(TEXT_16);
    stringBuffer.append(app.getIntegerValue(AppBaseuri  + "/eth004_dns_max_servers"));
    stringBuffer.append(TEXT_17);
    stringBuffer.append(app.getStringValue(AppBaseuri  + "/eth004_dns"));
    stringBuffer.append(TEXT_18);
    stringBuffer.append(app.getIntegerValue(AppBaseuri  + "/eth004_lwip_netif_hostname/" + 0));
    stringBuffer.append(TEXT_19);
    stringBuffer.append(app.getIntegerValue(AppBaseuri  + "/eth004_lwip_netif_status_callback/" + 0));
    stringBuffer.append(TEXT_20);
    stringBuffer.append(app.getIntegerValue(AppBaseuri  + "/eth004_lwip_netif_link_callback/" + 0));
    stringBuffer.append(TEXT_21);
    stringBuffer.append(app.getIntegerValue(AppBaseuri  + "/eth004_igmp_enable/" + 0));
    stringBuffer.append(TEXT_22);
    stringBuffer.append(app.getIntegerValue(AppBaseuri  + "/eth004_checksum_byhardware/" + 0));
    stringBuffer.append(TEXT_23);
     int Snmp_ppp = app.getIntegerValue(AppBaseuri  + "/eth004_dummy_snmp_ppp");
    stringBuffer.append(TEXT_24);
     if (Snmp_ppp == 0) {
    stringBuffer.append(TEXT_25);
     }else if(Snmp_ppp ==1) {
    stringBuffer.append(TEXT_26);
     }else if(Snmp_ppp ==2) {
    stringBuffer.append(TEXT_27);
     }
    stringBuffer.append(TEXT_28);
    stringBuffer.append(TEXT_29);
    return stringBuffer.toString();
  }
}
