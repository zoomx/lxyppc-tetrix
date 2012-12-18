/* Automatically generated from /home/iwow/work/paparazzi/paparazzi/conf/messages.xml */
/* Please DO NOT EDIT */
/* Macros to send and receive messages of class datalink */
#ifndef _VAR_MESSAGES2_datalink_H_
#define _VAR_MESSAGES2_datalink_H_
#include "downlink_transport.h"
#define DL_ACINFO 1
#define DL_MOVE_WP 2
#define DL_WIND_INFO 3
#define DL_SETTING 4
#define DL_BLOCK 5
#define DL_HITL_UBX 6
#define DL_HITL_INFRARED 7
#define DL_PING 8
#define DL_FORMATION_SLOT 9
#define DL_FORMATION_STATUS 10
#define DL_JOYSTICK_RAW 11
#define DL_COMMANDS_RAW 12
#define DL_DGPS_RAW 13
#define DL_GET_SETTING 16
#define DL_TCAS_RESOLVE 17
#define DL_WINDTURBINE_STATUS 50
#define DL_RC_3CH 51
#define DL_RC_4CH 52
#define DL_KITE_COMMAND 96
#define DL_PAYLOAD_COMMAND 97
#define DL_SET_ACTUATOR 100
#define DL_CSC_SERVO_CMD 101
#define DL_BOOZ2_FMS_COMMAND 149
#define DL_BOOZ_NAV_STICK 150
#define DL_EXTERNAL_FILTER_SOLUTION 151
#define DL_BOOZ_CAM_STICK 152
#define DL_MSG_datalink_NB 26

#define MSG_datalink_LENGTHS {0,(2+0+2+4+4+4+4+2+2+1),(2+0+1+1+4+4+4),(2+0+1+1+4+4+4),(2+0+1+1+4),(2+0+1+1),(2+0+1+1+1+1+nb_ubx_payload*1),(2+0+2+2+2+1),(2+0),(2+0+1+1+4+4+4),(2+0+1+1+1),(2+0+1+1+1+1),(2+0+1+1+nb_commands*1),(2+0+1+1+1+nb_rtcm*1),0,0,(2+0+1+1),(2+0+1+1+1),0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(2+0+1+1+4+4),(2+0+1+1+1),(2+0+1+1+1+1+1+1),0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(2+0+2+2),(2+0+1+1+nb_command*1),0,0,(2+0+2+1+1),(2+0+2+2+2+2),0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(2+0+1+1+4+4+4+4+1),(2+0+1+1+1+1+1),(2+0+1+1+4+4+4+4),(2+0+1+1+1),}

/*
 Size for non variable messages
23 : ACINFO
19 : BOOZ2_FMS_COMMAND
18 : EXTERNAL_FILTER_SOLUTION
14 : MOVE_WP
14 : WIND_INFO
14 : FORMATION_SLOT
10 : WINDTURBINE_STATUS
 8 : CSC_SERVO_CMD
 7 : HITL_INFRARED
 6 : SETTING
 6 : RC_4CH
 5 : BOOZ_NAV_STICK
 4 : JOYSTICK_RAW
 4 : KITE_COMMAND
 4 : SET_ACTUATOR
 3 : FORMATION_STATUS
 3 : TCAS_RESOLVE
 3 : RC_3CH
 3 : BOOZ_CAM_STICK
 2 : BLOCK
 2 : GET_SETTING
 0 : HITL_UBX
 0 : PING
 0 : COMMANDS_RAW
 0 : DGPS_RAW
 0 : PAYLOAD_COMMAND
*/
static inline void DOWNLINK_SEND_ACINFO(struct DownlinkTransport *tp, int16_t *_course, int32_t *_utm_east, int32_t *_utm_north, int32_t *_alt, uint32_t *_itow, uint16_t *_speed, int16_t *_climb, uint8_t *_ac_id){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+4+4+4+4+2+2+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+4+4+4+4+2+2+1)); 
	  tp->StartMessage(tp->impl, "ACINFO", DL_ACINFO, 0+2+4+4+4+4+2+2+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _course); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _utm_east); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _utm_north); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _alt); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _itow); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _speed); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _climb); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ac_id); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_MOVE_WP(struct DownlinkTransport *tp, uint8_t *_wp_id, uint8_t *_ac_id, int32_t *_lat, int32_t *_lon, int32_t *_alt){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+1+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+1+4+4+4)); 
	  tp->StartMessage(tp->impl, "MOVE_WP", DL_MOVE_WP, 0+1+1+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _wp_id); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ac_id); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _lat); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _lon); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _alt); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_WIND_INFO(struct DownlinkTransport *tp, uint8_t *_ac_id, uint8_t *_pad0, float *_east, float *_north, float *_airspeed){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+1+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+1+4+4+4)); 
	  tp->StartMessage(tp->impl, "WIND_INFO", DL_WIND_INFO, 0+1+1+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ac_id); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _pad0); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _east); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _north); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _airspeed); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_SETTING(struct DownlinkTransport *tp, uint8_t *_index, uint8_t *_ac_id, float *_value){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+1+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+1+4)); 
	  tp->StartMessage(tp->impl, "SETTING", DL_SETTING, 0+1+1+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _index); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ac_id); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _value); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_BLOCK(struct DownlinkTransport *tp, uint8_t *_block_id, uint8_t *_ac_id){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+1)); 
	  tp->StartMessage(tp->impl, "BLOCK", DL_BLOCK, 0+1+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _block_id); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ac_id); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_HITL_UBX(struct DownlinkTransport *tp, uint8_t *_class, uint8_t *_id, uint8_t *_ac_id, uint8_t nb_ubx_payload, uint8_t *_ubx_payload){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+1+1+1+nb_ubx_payload*1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+1+1+1+nb_ubx_payload*1)); 
	  tp->StartMessage(tp->impl, "HITL_UBX", DL_HITL_UBX, 0+1+1+1+1+nb_ubx_payload*1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _class); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _id); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ac_id); 
	  tp->PutBytes(tp->impl, DL_TYPE_ARRAY_LENGTH, 1, (void *) &nb_ubx_payload); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1 * nb_ubx_payload, (void *) _ubx_payload); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_HITL_INFRARED(struct DownlinkTransport *tp, int16_t *_roll, int16_t *_pitch, int16_t *_top, uint8_t *_ac_id){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2+1)); 
	  tp->StartMessage(tp->impl, "HITL_INFRARED", DL_HITL_INFRARED, 0+2+2+2+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _roll); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _pitch); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT16, 2, (void *) _top); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ac_id); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_PING(struct DownlinkTransport *tp ){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0)); 
	  tp->StartMessage(tp->impl, "PING", DL_PING, 0); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_FORMATION_SLOT(struct DownlinkTransport *tp, uint8_t *_ac_id, uint8_t *_mode, float *_slot_east, float *_slot_north, float *_slot_alt){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+1+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+1+4+4+4)); 
	  tp->StartMessage(tp->impl, "FORMATION_SLOT", DL_FORMATION_SLOT, 0+1+1+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ac_id); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _mode); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _slot_east); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _slot_north); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _slot_alt); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_FORMATION_STATUS(struct DownlinkTransport *tp, uint8_t *_ac_id, uint8_t *_leader_id, uint8_t *_status){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+1+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+1+1)); 
	  tp->StartMessage(tp->impl, "FORMATION_STATUS", DL_FORMATION_STATUS, 0+1+1+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ac_id); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _leader_id); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _status); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_JOYSTICK_RAW(struct DownlinkTransport *tp, uint8_t *_ac_id, int8_t *_roll, int8_t *_pitch, int8_t *_throttle){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+1+1+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+1+1+1)); 
	  tp->StartMessage(tp->impl, "JOYSTICK_RAW", DL_JOYSTICK_RAW, 0+1+1+1+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ac_id); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT8, 1, (void *) _roll); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT8, 1, (void *) _pitch); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT8, 1, (void *) _throttle); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_COMMANDS_RAW(struct DownlinkTransport *tp, uint8_t *_ac_id, uint8_t nb_commands, int8_t *_commands){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+1+nb_commands*1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+1+nb_commands*1)); 
	  tp->StartMessage(tp->impl, "COMMANDS_RAW", DL_COMMANDS_RAW, 0+1+1+nb_commands*1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ac_id); 
	  tp->PutBytes(tp->impl, DL_TYPE_ARRAY_LENGTH, 1, (void *) &nb_commands); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT8, 1 * nb_commands, (void *) _commands); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_DGPS_RAW(struct DownlinkTransport *tp, uint8_t *_ac_id, uint8_t *_length, uint8_t nb_rtcm, uint8_t *_rtcm){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+1+1+nb_rtcm*1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+1+1+nb_rtcm*1)); 
	  tp->StartMessage(tp->impl, "DGPS_RAW", DL_DGPS_RAW, 0+1+1+1+nb_rtcm*1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ac_id); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _length); 
	  tp->PutBytes(tp->impl, DL_TYPE_ARRAY_LENGTH, 1, (void *) &nb_rtcm); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1 * nb_rtcm, (void *) _rtcm); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_GET_SETTING(struct DownlinkTransport *tp, uint8_t *_index, uint8_t *_ac_id){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+1)); 
	  tp->StartMessage(tp->impl, "GET_SETTING", DL_GET_SETTING, 0+1+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _index); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ac_id); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_TCAS_RESOLVE(struct DownlinkTransport *tp, uint8_t *_ac_id, uint8_t *_ac_id_conflict, uint8_t *_resolve){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+1+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+1+1)); 
	  tp->StartMessage(tp->impl, "TCAS_RESOLVE", DL_TCAS_RESOLVE, 0+1+1+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ac_id); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ac_id_conflict); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _resolve); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_WINDTURBINE_STATUS(struct DownlinkTransport *tp, uint8_t *_ac_id, uint8_t *_tb_id, uint32_t *_sync_itow, uint32_t *_cycle_time){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+1+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+1+4+4)); 
	  tp->StartMessage(tp->impl, "WINDTURBINE_STATUS", DL_WINDTURBINE_STATUS, 0+1+1+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ac_id); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _tb_id); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _sync_itow); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT32, 4, (void *) _cycle_time); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_RC_3CH(struct DownlinkTransport *tp, uint8_t *_throttle_mode, int8_t *_roll, int8_t *_pitch){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+1+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+1+1)); 
	  tp->StartMessage(tp->impl, "RC_3CH", DL_RC_3CH, 0+1+1+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _throttle_mode); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT8, 1, (void *) _roll); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT8, 1, (void *) _pitch); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_RC_4CH(struct DownlinkTransport *tp, uint8_t *_ac_id, uint8_t *_mode, uint8_t *_throttle, int8_t *_roll, int8_t *_pitch, int8_t *_yaw){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+1+1+1+1+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+1+1+1+1+1)); 
	  tp->StartMessage(tp->impl, "RC_4CH", DL_RC_4CH, 0+1+1+1+1+1+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ac_id); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _mode); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _throttle); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT8, 1, (void *) _roll); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT8, 1, (void *) _pitch); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT8, 1, (void *) _yaw); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_KITE_COMMAND(struct DownlinkTransport *tp, uint16_t *_POWER, uint16_t *_TURN){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+2)); 
	  tp->StartMessage(tp->impl, "KITE_COMMAND", DL_KITE_COMMAND, 0+2+2); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _POWER); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _TURN); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_PAYLOAD_COMMAND(struct DownlinkTransport *tp, uint8_t *_ac_id, uint8_t nb_command, uint8_t *_command){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+1+nb_command*1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+1+nb_command*1)); 
	  tp->StartMessage(tp->impl, "PAYLOAD_COMMAND", DL_PAYLOAD_COMMAND, 0+1+1+nb_command*1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ac_id); 
	  tp->PutBytes(tp->impl, DL_TYPE_ARRAY_LENGTH, 1, (void *) &nb_command); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1 * nb_command, (void *) _command); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_SET_ACTUATOR(struct DownlinkTransport *tp, uint16_t *_value, uint8_t *_no, uint8_t *_ac_id){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+1+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+1+1)); 
	  tp->StartMessage(tp->impl, "SET_ACTUATOR", DL_SET_ACTUATOR, 0+2+1+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _value); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _no); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ac_id); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_CSC_SERVO_CMD(struct DownlinkTransport *tp, uint16_t *_servo_1, uint16_t *_servo_2, uint16_t *_servo_3, uint16_t *_servo_4){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2+2))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+2+2+2+2)); 
	  tp->StartMessage(tp->impl, "CSC_SERVO_CMD", DL_CSC_SERVO_CMD, 0+2+2+2+2); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _servo_1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _servo_2); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _servo_3); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT16, 2, (void *) _servo_4); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_BOOZ2_FMS_COMMAND(struct DownlinkTransport *tp, uint8_t *_h_mode, uint8_t *_v_mode, int32_t *_v_sp, int32_t *_h_sp_1, int32_t *_h_sp_2, int32_t *_h_sp_3, uint8_t *_ac_id){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+1+4+4+4+4+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+1+4+4+4+4+1)); 
	  tp->StartMessage(tp->impl, "BOOZ2_FMS_COMMAND", DL_BOOZ2_FMS_COMMAND, 0+1+1+4+4+4+4+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _h_mode); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _v_mode); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _v_sp); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _h_sp_1); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _h_sp_2); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT32, 4, (void *) _h_sp_3); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ac_id); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_BOOZ_NAV_STICK(struct DownlinkTransport *tp, uint8_t *_ac_id, int8_t *_vx_sp, int8_t *_vy_sp, int8_t *_vz_sp, int8_t *_r_sp){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+1+1+1+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+1+1+1+1)); 
	  tp->StartMessage(tp->impl, "BOOZ_NAV_STICK", DL_BOOZ_NAV_STICK, 0+1+1+1+1+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ac_id); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT8, 1, (void *) _vx_sp); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT8, 1, (void *) _vy_sp); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT8, 1, (void *) _vz_sp); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT8, 1, (void *) _r_sp); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_EXTERNAL_FILTER_SOLUTION(struct DownlinkTransport *tp, uint8_t *_ac_id, uint8_t *_status, float *_x, float *_xd, float *_y, float *_yd){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+1+4+4+4+4))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+1+4+4+4+4)); 
	  tp->StartMessage(tp->impl, "EXTERNAL_FILTER_SOLUTION", DL_EXTERNAL_FILTER_SOLUTION, 0+1+1+4+4+4+4); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ac_id); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _status); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _x); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _xd); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _y); 
	  tp->PutBytes(tp->impl, DL_TYPE_FLOAT, 4, (void *) _yd); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}

static inline void DOWNLINK_SEND_BOOZ_CAM_STICK(struct DownlinkTransport *tp, uint8_t *_ac_id, int8_t *_tilt, int8_t *_pan){ 
	if (tp->CheckFreeSpace(tp->impl, tp->SizeOf(tp->impl, 0+1+1+1))) {
	  tp->CountBytes(tp->impl, tp->SizeOf(tp->impl, 0+1+1+1)); 
	  tp->StartMessage(tp->impl, "BOOZ_CAM_STICK", DL_BOOZ_CAM_STICK, 0+1+1+1); 
	  tp->PutBytes(tp->impl, DL_TYPE_UINT8, 1, (void *) _ac_id); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT8, 1, (void *) _tilt); 
	  tp->PutBytes(tp->impl, DL_TYPE_INT8, 1, (void *) _pan); 
	  tp->EndMessage(tp->impl); 
	} else 
	  tp->Overrun(tp->impl); 
}


#define DL_ACINFO_course(_payload) ((int16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_ACINFO_utm_east(_payload) ((int32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24))
#define DL_ACINFO_utm_north(_payload) ((int32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24))
#define DL_ACINFO_alt(_payload) ((int32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24))
#define DL_ACINFO_itow(_payload) ((uint32_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8|((uint32_t)*((uint8_t*)_payload+16+2))<<16|((uint32_t)*((uint8_t*)_payload+16+3))<<24))
#define DL_ACINFO_speed(_payload) ((uint16_t)(*((uint8_t*)_payload+20)|*((uint8_t*)_payload+20+1)<<8))
#define DL_ACINFO_climb(_payload) ((int16_t)(*((uint8_t*)_payload+22)|*((uint8_t*)_payload+22+1)<<8))
#define DL_ACINFO_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+24)))

#define DL_MOVE_WP_wp_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_MOVE_WP_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_MOVE_WP_lat(_payload) ((int32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24))
#define DL_MOVE_WP_lon(_payload) ((int32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24))
#define DL_MOVE_WP_alt(_payload) ((int32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24))

#define DL_WIND_INFO_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_WIND_INFO_pad0(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_WIND_INFO_east(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24); _f.f; }))
#define DL_WIND_INFO_north(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24); _f.f; }))
#define DL_WIND_INFO_airspeed(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24); _f.f; }))

#define DL_SETTING_index(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_SETTING_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_SETTING_value(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24); _f.f; }))

#define DL_BLOCK_block_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_BLOCK_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))

#define DL_HITL_UBX_class(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_HITL_UBX_id(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_HITL_UBX_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+4)))
#define DL_HITL_UBX_ubx_payload_length(_payload) ((uint8_t)(*((uint8_t*)_payload+5)))
#define DL_HITL_UBX_ubx_payload(_payload) ((uint8_t*)(_payload+6))

#define DL_HITL_INFRARED_roll(_payload) ((int16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_HITL_INFRARED_pitch(_payload) ((int16_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8))
#define DL_HITL_INFRARED_top(_payload) ((int16_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8))
#define DL_HITL_INFRARED_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+8)))


#define DL_FORMATION_SLOT_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_FORMATION_SLOT_mode(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_FORMATION_SLOT_slot_east(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24); _f.f; }))
#define DL_FORMATION_SLOT_slot_north(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24); _f.f; }))
#define DL_FORMATION_SLOT_slot_alt(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24); _f.f; }))

#define DL_FORMATION_STATUS_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_FORMATION_STATUS_leader_id(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_FORMATION_STATUS_status(_payload) ((uint8_t)(*((uint8_t*)_payload+4)))

#define DL_JOYSTICK_RAW_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_JOYSTICK_RAW_roll(_payload) ((int8_t)(*((uint8_t*)_payload+3)))
#define DL_JOYSTICK_RAW_pitch(_payload) ((int8_t)(*((uint8_t*)_payload+4)))
#define DL_JOYSTICK_RAW_throttle(_payload) ((int8_t)(*((uint8_t*)_payload+5)))

#define DL_COMMANDS_RAW_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_COMMANDS_RAW_commands_length(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_COMMANDS_RAW_commands(_payload) ((int8_t*)(_payload+4))

#define DL_DGPS_RAW_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_DGPS_RAW_length(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_DGPS_RAW_rtcm_length(_payload) ((uint8_t)(*((uint8_t*)_payload+4)))
#define DL_DGPS_RAW_rtcm(_payload) ((uint8_t*)(_payload+5))

#define DL_GET_SETTING_index(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_GET_SETTING_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))

#define DL_TCAS_RESOLVE_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_TCAS_RESOLVE_ac_id_conflict(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_TCAS_RESOLVE_resolve(_payload) ((uint8_t)(*((uint8_t*)_payload+4)))

#define DL_WINDTURBINE_STATUS_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_WINDTURBINE_STATUS_tb_id(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_WINDTURBINE_STATUS_sync_itow(_payload) ((uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24))
#define DL_WINDTURBINE_STATUS_cycle_time(_payload) ((uint32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24))

#define DL_RC_3CH_throttle_mode(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_RC_3CH_roll(_payload) ((int8_t)(*((uint8_t*)_payload+3)))
#define DL_RC_3CH_pitch(_payload) ((int8_t)(*((uint8_t*)_payload+4)))

#define DL_RC_4CH_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_RC_4CH_mode(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_RC_4CH_throttle(_payload) ((uint8_t)(*((uint8_t*)_payload+4)))
#define DL_RC_4CH_roll(_payload) ((int8_t)(*((uint8_t*)_payload+5)))
#define DL_RC_4CH_pitch(_payload) ((int8_t)(*((uint8_t*)_payload+6)))
#define DL_RC_4CH_yaw(_payload) ((int8_t)(*((uint8_t*)_payload+7)))

#define DL_KITE_COMMAND_POWER(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_KITE_COMMAND_TURN(_payload) ((uint16_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8))

#define DL_PAYLOAD_COMMAND_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_PAYLOAD_COMMAND_command_length(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_PAYLOAD_COMMAND_command(_payload) ((uint8_t*)(_payload+4))

#define DL_SET_ACTUATOR_value(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_SET_ACTUATOR_no(_payload) ((uint8_t)(*((uint8_t*)_payload+4)))
#define DL_SET_ACTUATOR_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+5)))

#define DL_CSC_SERVO_CMD_servo_1(_payload) ((uint16_t)(*((uint8_t*)_payload+2)|*((uint8_t*)_payload+2+1)<<8))
#define DL_CSC_SERVO_CMD_servo_2(_payload) ((uint16_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8))
#define DL_CSC_SERVO_CMD_servo_3(_payload) ((uint16_t)(*((uint8_t*)_payload+6)|*((uint8_t*)_payload+6+1)<<8))
#define DL_CSC_SERVO_CMD_servo_4(_payload) ((uint16_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8))

#define DL_BOOZ2_FMS_COMMAND_h_mode(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_BOOZ2_FMS_COMMAND_v_mode(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_BOOZ2_FMS_COMMAND_v_sp(_payload) ((int32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24))
#define DL_BOOZ2_FMS_COMMAND_h_sp_1(_payload) ((int32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24))
#define DL_BOOZ2_FMS_COMMAND_h_sp_2(_payload) ((int32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24))
#define DL_BOOZ2_FMS_COMMAND_h_sp_3(_payload) ((int32_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8|((uint32_t)*((uint8_t*)_payload+16+2))<<16|((uint32_t)*((uint8_t*)_payload+16+3))<<24))
#define DL_BOOZ2_FMS_COMMAND_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+20)))

#define DL_BOOZ_NAV_STICK_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_BOOZ_NAV_STICK_vx_sp(_payload) ((int8_t)(*((uint8_t*)_payload+3)))
#define DL_BOOZ_NAV_STICK_vy_sp(_payload) ((int8_t)(*((uint8_t*)_payload+4)))
#define DL_BOOZ_NAV_STICK_vz_sp(_payload) ((int8_t)(*((uint8_t*)_payload+5)))
#define DL_BOOZ_NAV_STICK_r_sp(_payload) ((int8_t)(*((uint8_t*)_payload+6)))

#define DL_EXTERNAL_FILTER_SOLUTION_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_EXTERNAL_FILTER_SOLUTION_status(_payload) ((uint8_t)(*((uint8_t*)_payload+3)))
#define DL_EXTERNAL_FILTER_SOLUTION_x(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+4)|*((uint8_t*)_payload+4+1)<<8|((uint32_t)*((uint8_t*)_payload+4+2))<<16|((uint32_t)*((uint8_t*)_payload+4+3))<<24); _f.f; }))
#define DL_EXTERNAL_FILTER_SOLUTION_xd(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+8)|*((uint8_t*)_payload+8+1)<<8|((uint32_t)*((uint8_t*)_payload+8+2))<<16|((uint32_t)*((uint8_t*)_payload+8+3))<<24); _f.f; }))
#define DL_EXTERNAL_FILTER_SOLUTION_y(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+12)|*((uint8_t*)_payload+12+1)<<8|((uint32_t)*((uint8_t*)_payload+12+2))<<16|((uint32_t)*((uint8_t*)_payload+12+3))<<24); _f.f; }))
#define DL_EXTERNAL_FILTER_SOLUTION_yd(_payload) (({ union { uint32_t u; float f; } _f; _f.u = (uint32_t)(*((uint8_t*)_payload+16)|*((uint8_t*)_payload+16+1)<<8|((uint32_t)*((uint8_t*)_payload+16+2))<<16|((uint32_t)*((uint8_t*)_payload+16+3))<<24); _f.f; }))

#define DL_BOOZ_CAM_STICK_ac_id(_payload) ((uint8_t)(*((uint8_t*)_payload+2)))
#define DL_BOOZ_CAM_STICK_tilt(_payload) ((int8_t)(*((uint8_t*)_payload+3)))
#define DL_BOOZ_CAM_STICK_pan(_payload) ((int8_t)(*((uint8_t*)_payload+4)))
#endif // _VAR_MESSAGES2_datalink_H_
