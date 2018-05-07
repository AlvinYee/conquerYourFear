/*
 * _HDL_RMH_Cfg.h
 *
 *  Created on: 20th,Feb,2018
 *      Author: yech
 */
/*[[[cog
print('    [info]: handling template _HDL_RMH_Cfg.h starts')
import sys
sys.path.append('../')
sys.path.append('../../')
import cog
from PkMqXmlParser import MdMqxmlParser
xmlFile = r'C:\workspace\CocoNut\description\Coco.xml'
mqxml = MdMqxmlParser.MqXmlParser(xmlFile)
]]]*/
//[[[end]]]
#ifndef HDL_RMH_CFG_H_
#define HDL_RMH_CFG_H_

/* message level configuration*/
#define I2CCAN_RX_MSG_WHEEL_SPEED_1_CFG \
/*[[[cog
 cog.out(mqxml.get_msg_element('wheelSpeed_1', 'enable'))
 ]]]*/
 //[[[end]]]
#define I2CCAN_RX_MSG_WHEEL_SPEED_1_E2E_PROTECTION_CFG \
/*[[[cog
 cog.out(mqxml.get_msg_element('wheelSpeed_1', 'E2EProtection'))
 ]]]*/
 //[[[end]]]

#define I2CCAN_RX_MSG_WHEEL_SPEED_2_CFG \
/*[[[cog
 cog.out(mqxml.get_msg_element('wheelSpeed_2', 'enable'))
 ]]]*/
 //[[[end]]]
#define I2CCAN_RX_MSG_WHEEL_SPEED_2_E2E_PROTECTION_CFG \
/*[[[cog
 cog.out(mqxml.get_msg_element('wheelSpeed_2', 'E2EProtection'))
 ]]]*/
 //[[[end]]]
#if I2CCAN_RX_MSG_WHEEL_SPEED_2_CFG > FALSE && I2CCAN_RX_MSG_WHEEL_SPEED_1_CFG == FALSE
#error "WHEEL_SPEED_1 must be used prior to WHEEL_SPEED_2"
#endif

#define I2CCAN_RX_MSG_POWER_MODE_CFG \
/*[[[cog
 cog.out(mqxml.get_msg_element('powerMode', 'enable'))
 ]]]*/
 //[[[end]]]
#define I2CCAN_RX_MSG_POWER_MODE_E2E_PROTECTION_CFG \
/*[[[cog
 cog.out(mqxml.get_msg_element('powerMode', 'E2EProtection'))
 ]]]*/
 //[[[end]]]

#define I2CCAN_RX_MSG_VEHICLE_SPEED_CFG \
/*[[[cog
 cog.out(mqxml.get_msg_element('vehicleSpeed', 'enable'))
 ]]]*/
 //[[[end]]]
#define I2CCAN_RX_MSG_VEHICLE_SPEED_E2E_PROTECTION_CFG \
/*[[[cog
 cog.out(mqxml.get_msg_element('vehicleSpeed', 'E2EProtection'))
 ]]]*/
 //[[[end]]]

/* Function codes of receive messages */
#define HDL_RMH_I2C_FC_STATUS_HACO			0x33u	/* function code of the status message of the HaCo */
#define HDL_RMH_I2C_FC_SW_VERSION_COCO		0xA5u	/* function code of the request message for the SW version */
#define HDL_RMH_I2C_FC_LOCK_REQUEST			0xD1u	/* function code of the lock request message */

#if I2CCAN_RX_MSG_WHEEL_SPEED_1_CFG > FALSE
#define HDL_RMH_I2C_FC_ESP_10 				HDL_RMH_I2C_FC_WHEEL_SPEED_1 /* compatibility with GEN3 platform project */
#define HDL_RMH_I2C_FC_WHEEL_SPEED_1 \
/*[[[cog
 cog.out(mqxml.get_msg_element('wheelSpeed_1', 'funcCode'))
 ]]]*/
 //[[[end]]]
#endif
#if I2CCAN_RX_MSG_WHEEL_SPEED_2_CFG > FALSE
#define HDL_RMH_I2C_FC_WHEEL_SPEED_2 \
/*[[[cog
 cog.out(mqxml.get_msg_element('wheelSpeed_2', 'funcCode'))
 ]]]*/
 //[[[end]]]
#endif
#if I2CCAN_RX_MSG_POWER_MODE_CFG > FALSE
#define HDL_RMH_I2C_FC_POWER_MODE \
/*[[[cog
 cog.out(mqxml.get_msg_element('powerMode', 'funcCode'))
 ]]]*/
 //[[[end]]]
#endif
#if I2CCAN_RX_MSG_VEHICLE_SPEED_CFG > FALSE
#define HDL_RMH_I2C_FC_VEHICLE_SPEED \
/*[[[cog
 cog.out(mqxml.get_msg_element('vehicleSpeed', 'funcCode'))
 ]]]*/
 //[[[end]]]
#endif

/* msg buffer mapping configuration*/
#if I2CCAN_RX_MSG_WHEEL_SPEED_1_CFG > FALSE
#define SWSW_coco_buffer_esp_10 				RxBufferWheelSpeed1 /* compatibility with GEN3 platform project */
#define RxBufferWheelSpeed1 \
/*[[[cog
 cog.out(mqxml.get_msg_element('wheelSpeed_1', 'actualName'))
 ]]]*/
 //[[[end]]]
#endif
#if I2CCAN_RX_MSG_WHEEL_SPEED_2_CFG > FALSE
#define RxBufferWheelSpeed2 \
/*[[[cog
 cog.out(mqxml.get_msg_element('wheelSpeed_2', 'actualName'))
 ]]]*/
 //[[[end]]]
#endif
#if I2CCAN_RX_MSG_POWER_MODE_CFG > FALSE
#define RxBufferPowerMode \
/*[[[cog
 cog.out(mqxml.get_msg_element('powerMode', 'actualName'))
 ]]]*/
 //[[[end]]]
#endif
#if I2CCAN_RX_MSG_VEHICLE_SPEED_CFG > FALSE
#define RxBufferVehicleSpeed \
/*[[[cog
 cog.out(mqxml.get_msg_element('vehicleSpeed', 'actualName'))
 ]]]*/
 //[[[end]]]
#endif

/* length of the receive message buffers */
#if I2CCAN_RX_MSG_WHEEL_SPEED_1_CFG > FALSE
#define HDL_RMH_ESP_10_LENGTH				HDL_RMH_WHEEL_SPEED_1_CAN_LENGTH	/* compatibility with GEN3 platform project */
#define HDL_RMH_WHEEL_SPEED_1_CAN_LENGTH \
/*[[[cog
 cog.out(mqxml.get_msg_element('wheelSpeed_1', 'msgLength'))
 ]]]*/
 //[[[end]]]
#endif
#if I2CCAN_RX_MSG_WHEEL_SPEED_2_CFG > FALSE
#define HDL_RMH_WHEEL_SPEED_2_CAN_LENGTH \
/*[[[cog
 cog.out(mqxml.get_msg_element('wheelSpeed_2', 'msgLength'))
 ]]]*/
 //[[[end]]]
#endif
#if I2CCAN_RX_MSG_POWER_MODE_CFG > FALSE
#define HDL_RMH_POWER_MODE_CAN_LENGTH \
/*[[[cog
 cog.out(mqxml.get_msg_element('powerMode', 'msgLength'))
 ]]]*/
 //[[[end]]]
#endif
#if I2CCAN_RX_MSG_VEHICLE_SPEED_CFG > FALSE
#define HDL_RMH_VEHICLE_SPEED_CAN_LENGTH \
/*[[[cog
 cog.out(mqxml.get_msg_element('vehicleSpeed', 'msgLength'))
 ]]]*/
 //[[[end]]]
#endif

/* signal level configuration*/
#define I2CCAN_RX_SIG_WHEEL_SPEED_1_CRC_CFG \
/*[[[cog
 cog.out(mqxml.get_signal_element('wheelSpeed_1','WHEEL_SPEED_1_CRC', 'enable'))
 ]]]*/
 //[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_1_ALIVE_CFG \
/*[[[cog
 cog.out(mqxml.get_signal_element('wheelSpeed_1', 'WHEEL_SPEED_1_ALIVE', 'enable'))
 ]]]*/
 //[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_1_VALIDITY_FR_CFG \
/*[[[cog
 cog.out(mqxml.get_signal_element('wheelSpeed_1', 'WHEEL_SPEED_1_VALIDITY_FR', 'enable'))
 ]]]*/
 //[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_1_VALIDITY_FL_CFG \
/*[[[cog
 cog.out(mqxml.get_signal_element('wheelSpeed_1', 'WHEEL_SPEED_1_VALIDITY_FL', 'enable'))
 ]]]*/
 //[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_1_VALIDITY_RR_CFG \
/*[[[cog
 cog.out(mqxml.get_signal_element('wheelSpeed_1', 'WHEEL_SPEED_1_VALIDITY_RR', 'enable'))
 ]]]*/
 //[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_1_VALIDITY_RL_CFG \
/*[[[cog
 cog.out(mqxml.get_signal_element('wheelSpeed_1', 'WHEEL_SPEED_1_VALIDITY_RL', 'enable'))
 ]]]*/
 //[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_1_FR_CFG \
/*[[[cog
 cog.out(mqxml.get_signal_element('wheelSpeed_1', 'WHEEL_SPEED_1_FR', 'enable'))
 ]]]*/
 //[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_1_FL_CFG \
/*[[[cog
 cog.out(mqxml.get_signal_element('wheelSpeed_1', 'WHEEL_SPEED_1_FL', 'enable'))
 ]]]*/
 //[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_1_RR_CFG \
/*[[[cog
 cog.out(mqxml.get_signal_element('wheelSpeed_1', 'WHEEL_SPEED_1_RR', 'enable'))
 ]]]*/
 //[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_1_RL_CFG \
/*[[[cog
 cog.out(mqxml.get_signal_element('wheelSpeed_1', 'WHEEL_SPEED_1_RL', 'enable'))
 ]]]*/
 //[[[end]]]

#define I2CCAN_RX_SIG_WHEEL_SPEED_2_CRC_CFG \
/*[[[cog
 cog.out(mqxml.get_signal_element('wheelSpeed_2', 'WHEEL_SPEED_2_CRC', 'enable'))
 ]]]*/
 //[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_2_ALIVE_CFG \
/*[[[cog
 cog.out(mqxml.get_signal_element('wheelSpeed_2', 'WHEEL_SPEED_2_ALIVE', 'enable'))
 ]]]*/
 //[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_2_VALIDITY_FR_CFG \
/*[[[cog
 cog.out(mqxml.get_signal_element('wheelSpeed_2', 'WHEEL_SPEED_2_VALIDITY_FR', 'enable'))
 ]]]*/
 //[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_2_VALIDITY_FL_CFG \
/*[[[cog
 cog.out(mqxml.get_signal_element('wheelSpeed_2', 'WHEEL_SPEED_2_VALIDITY_FL', 'enable'))
 ]]]*/
 //[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_2_VALIDITY_RR_CFG \
/*[[[cog
 cog.out(mqxml.get_signal_element('wheelSpeed_2', 'WHEEL_SPEED_2_VALIDITY_RR', 'enable'))
 ]]]*/
 //[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_2_VALIDITY_RL_CFG \
/*[[[cog
 cog.out(mqxml.get_signal_element('wheelSpeed_2', 'WHEEL_SPEED_2_VALIDITY_RL', 'enable'))
 ]]]*/
 //[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_2_FR_CFG \
/*[[[cog
 cog.out(mqxml.get_signal_element('wheelSpeed_2', 'WHEEL_SPEED_2_FR', 'enable'))
 ]]]*/
 //[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_2_FL_CFG \
/*[[[cog
 cog.out(mqxml.get_signal_element('wheelSpeed_2', 'WHEEL_SPEED_2_FL', 'enable'))
 ]]]*/
 //[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_2_RR_CFG \
/*[[[cog
 cog.out(mqxml.get_signal_element('wheelSpeed_2', 'WHEEL_SPEED_2_RR', 'enable'))
 ]]]*/
 //[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_2_RL_CFG \
/*[[[cog
 cog.out(mqxml.get_signal_element('wheelSpeed_2', 'WHEEL_SPEED_2_RL', 'enable'))
 ]]]*/
 //[[[end]]]

#define I2CCAN_RX_SIG_POWER_MODE_CRC_CFG \
/*[[[cog
 cog.out(mqxml.get_signal_element('powerMode', 'POWER_MODE_CRC', 'enable'))
 ]]]*/
 //[[[end]]]
#define I2CCAN_RX_SIG_POWER_MODE_ALIVE_CFG \
/*[[[cog
 cog.out(mqxml.get_signal_element('powerMode', 'POWER_MODE_ALIVE', 'enable'))
 ]]]*/
 //[[[end]]]
#define I2CCAN_RX_SIG_POWER_MODE_VALIDITY_CFG \
/*[[[cog
 cog.out(mqxml.get_signal_element('powerMode', 'POWER_MODE_VALIDITY', 'enable'))
 ]]]*/
 //[[[end]]]
#define I2CCAN_RX_SIG_POWER_MODE_CFG \
/*[[[cog
 cog.out(mqxml.get_signal_element('powerMode', 'POWER_MODE', 'enable'))
 ]]]*/
 //[[[end]]]

#define I2CCAN_RX_SIG_VEHICLE_SPEED_CRC_CFG \
/*[[[cog
 cog.out(mqxml.get_signal_element('vehicleSpeed', 'VEHICLE_SPEED_CRC', 'enable'))
 ]]]*/
 //[[[end]]]
#define I2CCAN_RX_SIG_VEHICLE_SPEED_ALIVE_CFG \
/*[[[cog
 cog.out(mqxml.get_signal_element('vehicleSpeed', 'VEHICLE_SPEED_ALIVE', 'enable'))
 ]]]*/
 //[[[end]]]
#define I2CCAN_RX_SIG_VEHICLE_SPEED_VALIDITY_CFG \
/*[[[cog
 cog.out(mqxml.get_signal_element('vehicleSpeed', 'VEHICLE_SPEED_VALIDITY', 'enable'))
 ]]]*/
 //[[[end]]]
#define I2CCAN_RX_SIG_VEHICLE_SPEED_CFG \
/*[[[cog
 cog.out(mqxml.get_signal_element('vehicleSpeed', 'VEHICLE_SPEED', 'enable'))
 ]]]*/
 //[[[end]]]

/* the signal access macro will be defined in I2CCAN_Par.h that handles message layout and mapped here */
#define I2CCAN_RX_SIG_WHEEL_SPEED_1_CRC \
/*[[[cog
cog.out('b_'+mqxml.get_signal_element('wheelSpeed_1','WHEEL_SPEED_1_CRC', 'actualName')+'_b')
]]]*/
//[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_1_ALIVE \
/*[[[cog
cog.out('b_'+mqxml.get_signal_element('wheelSpeed_1','WHEEL_SPEED_1_ALIVE', 'actualName')+'_b')
]]]*/
//[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_1_VALIDITY_FR \
/*[[[cog
cog.out('b_'+mqxml.get_signal_element('wheelSpeed_1','WHEEL_SPEED_1_VALIDITY_FR', 'actualName')+'_b')
]]]*/
//[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_1_VALIDITY_FL \
/*[[[cog
cog.out('b_'+mqxml.get_signal_element('wheelSpeed_1','WHEEL_SPEED_1_VALIDITY_FL', 'actualName')+'_b')
]]]*/
//[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_1_VALIDITY_RR \
/*[[[cog
cog.out('b_'+mqxml.get_signal_element('wheelSpeed_1','WHEEL_SPEED_1_VALIDITY_RR', 'actualName')+'_b')
]]]*/
//[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_1_VALIDITY_RL \
/*[[[cog
cog.out('b_'+mqxml.get_signal_element('wheelSpeed_1','WHEEL_SPEED_1_VALIDITY_RL', 'actualName')+'_b')
]]]*/
//[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_1_FR \
/*[[[cog
cog.out('b_'+mqxml.get_signal_element('wheelSpeed_1','WHEEL_SPEED_1_FR', 'actualName')+'_b')
]]]*/
//[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_1_FL \
/*[[[cog
cog.out('b_'+mqxml.get_signal_element('wheelSpeed_1','WHEEL_SPEED_1_FL', 'actualName')+'_b')
]]]*/
//[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_1_RR \
/*[[[cog
cog.out('b_'+mqxml.get_signal_element('wheelSpeed_1','WHEEL_SPEED_1_RR', 'actualName')+'_b')
]]]*/
//[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_1_RL \
/*[[[cog
cog.out('b_'+mqxml.get_signal_element('wheelSpeed_1','WHEEL_SPEED_1_RL', 'actualName')+'_b')
]]]*/
//[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_2_CRC \
/*[[[cog
cog.out('b_'+mqxml.get_signal_element('wheelSpeed_2','WHEEL_SPEED_2_CRC', 'actualName')+'_b')
]]]*/
//[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_2_ALIVE \
/*[[[cog
cog.out('b_'+mqxml.get_signal_element('wheelSpeed_2','WHEEL_SPEED_2_ALIVE', 'actualName')+'_b')
]]]*/
//[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_2_VALIDITY_FR \
/*[[[cog
cog.out('b_'+mqxml.get_signal_element('wheelSpeed_2','WHEEL_SPEED_2_VALIDITY_FR', 'actualName')+'_b')
]]]*/
//[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_2_VALIDITY_FL \
/*[[[cog
cog.out('b_'+mqxml.get_signal_element('wheelSpeed_2','WHEEL_SPEED_2_VALIDITY_FL', 'actualName')+'_b')
]]]*/
//[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_2_VALIDITY_RR \
/*[[[cog
cog.out('b_'+mqxml.get_signal_element('wheelSpeed_2','WHEEL_SPEED_2_VALIDITY_RR', 'actualName')+'_b')
]]]*/
//[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_2_VALIDITY_RL \
/*[[[cog
cog.out('b_'+mqxml.get_signal_element('wheelSpeed_2','WHEEL_SPEED_2_VALIDITY_RL', 'actualName')+'_b')
]]]*/
//[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_2_FR \
/*[[[cog
cog.out('b_'+mqxml.get_signal_element('wheelSpeed_2','WHEEL_SPEED_2_FR', 'actualName')+'_b')
]]]*/
//[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_2_FL \
/*[[[cog
cog.out('b_'+mqxml.get_signal_element('wheelSpeed_2','WHEEL_SPEED_2_FL', 'actualName')+'_b')
]]]*/
//[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_2_RR \
/*[[[cog
cog.out('b_'+mqxml.get_signal_element('wheelSpeed_2','WHEEL_SPEED_2_RR', 'actualName')+'_b')
]]]*/
//[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_2_RL \
/*[[[cog
cog.out('b_'+mqxml.get_signal_element('wheelSpeed_2','WHEEL_SPEED_2_RL', 'actualName')+'_b')
]]]*/
//[[[end]]]
#define I2CCAN_RX_SIG_POWER_MODE_CRC \
/*[[[cog
cog.out('b_'+mqxml.get_signal_element('powerMode','POWER_MODE_CRC', 'actualName')+'_b')
]]]*/
//[[[end]]]
#define I2CCAN_RX_SIG_POWER_MODE_ALIVE \
/*[[[cog
cog.out('b_'+mqxml.get_signal_element('powerMode','POWER_MODE_ALIVE', 'actualName')+'_b')
]]]*/
//[[[end]]]
#define I2CCAN_RX_SIG_POWER_MODE_VALIDITY \
/*[[[cog
cog.out('b_'+mqxml.get_signal_element('powerMode','POWER_MODE_VALIDITY', 'actualName')+'_b')
]]]*/
//[[[end]]]
#define I2CCAN_RX_SIG_POWER_MODE \
/*[[[cog
cog.out('b_'+mqxml.get_signal_element('powerMode','POWER_MODE', 'actualName')+'_b')
]]]*/
//[[[end]]]
#define I2CCAN_RX_SIG_VEHICLE_SPEED_CRC \
/*[[[cog
cog.out('b_'+mqxml.get_signal_element('vehicleSpeed','VEHICLE_SPEED_CRC', 'actualName')+'_b')
]]]*/
//[[[end]]]
#define I2CCAN_RX_SIG_VEHICLE_SPEED_ALIVE \
/*[[[cog
cog.out('b_'+mqxml.get_signal_element('vehicleSpeed','VEHICLE_SPEED_ALIVE', 'actualName')+'_b')
]]]*/
//[[[end]]]
#define I2CCAN_RX_SIG_VEHICLE_SPEED_VALIDITY \
/*[[[cog
cog.out('b_'+mqxml.get_signal_element('vehicleSpeed','VEHICLE_SPEED_VALIDITY', 'actualName')+'_b')
]]]*/
//[[[end]]]
#define I2CCAN_RX_SIG_VEHICLE_SPEED \
/*[[[cog
cog.out('b_'+mqxml.get_signal_element('vehicleSpeed','VEHICLE_SPEED', 'actualName')+'_b')
]]]*/
//[[[end]]]

#define I2CCAN_RX_SIG_WHEEL_SPEED_1_CRC_OFFSET \
/*[[[cog
cog.out(mqxml.get_signal_element('wheelSpeed_1','WHEEL_SPEED_1_CRC', 'crcOffset'))
]]]*/
//[[[end]]]
#define I2CCAN_RX_SIG_WHEEL_SPEED_2_CRC_OFFSET \
/*[[[cog
cog.out(mqxml.get_signal_element('wheelSpeed_2','WHEEL_SPEED_2_CRC', 'crcOffset'))
]]]*/
//[[[end]]]
#define I2CCAN_RX_SIG_POWER_MODE_CRC_OFFSET \
/*[[[cog
cog.out(mqxml.get_signal_element('powerMode','POWER_MODE_CRC', 'crcOffset'))
]]]*/
//[[[end]]]
#define I2CCAN_RX_SIG_VEHICLE_SPEED_CRC_OFFSET \
/*[[[cog
cog.out(mqxml.get_signal_element('vehicleSpeed','VEHICLE_SPEED_CRC', 'crcOffset'))
]]]*/
//[[[end]]]

#if I2CCAN_RX_MSG_VEHICLE_SPEED_E2E_PROTECTION_CFG > FALSE && I2CCAN_RX_SIG_VEHICLE_SPEED_CRC_CFG== FALSE && I2CCAN_RX_SIG_VEHICLE_SPEED_ALIVE_CFG == FALSE
#error "I2CCAN_RX_MSG_VEHICLE_SPEED E2E configuration error"
#endif
#if I2CCAN_RX_MSG_WHEEL_SPEED_1_E2E_PROTECTION_CFG > FALSE && I2CCAN_RX_SIG_WHEEL_SPEED_1_CRC_CFG== FALSE && I2CCAN_RX_SIG_WHEEL_SPEED_1_ALIVE_CFG == FALSE
#error "I2CCAN_RX_MSG_WHEEL_SPEED_1 E2E configuration error"
#endif
#if I2CCAN_RX_MSG_WHEEL_SPEED_2_E2E_PROTECTION_CFG > FALSE && I2CCAN_RX_SIG_WHEEL_SPEED_2_CRC_CFG== FALSE && I2CCAN_RX_SIG_WHEEL_SPEED_2_ALIVE_CFG == FALSE
#error "I2CCAN_RX_MSG_WHEEL_SPEED_2 E2E configuration error"
#endif
/*[[[cog
print('    [info]: handling template _HDL_RMH_Cfg.h ends')
]]]*/
//[[[end]]]
#endif /* HDL_RMH_CFG_H_ */
