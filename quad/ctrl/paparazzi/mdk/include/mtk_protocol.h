/* Generated from /home/iwow/work/paparazzi/paparazzi/conf/mtk.xml */
/* Please DO NOT EDIT */

#define MTK_DIY14_SYNC1 0xB5
#define MTK_DIY14_SYNC2 0x62

#define MTK_DIY14_ID 0x01

#define MTK_DIY14_NAV_ID 0x05
#define MTK_DIY14_NAV_LAT(_mtk_payload) (int32_t)(*((uint8_t*)_mtk_payload+3+0)|*((uint8_t*)_mtk_payload+2+0)<<8|((int32_t)*((uint8_t*)_mtk_payload+1+0))<<16|((int32_t)*((uint8_t*)_mtk_payload+0))<<24)
#define MTK_DIY14_NAV_LON(_mtk_payload) (int32_t)(*((uint8_t*)_mtk_payload+3+4)|*((uint8_t*)_mtk_payload+2+4)<<8|((int32_t)*((uint8_t*)_mtk_payload+1+4))<<16|((int32_t)*((uint8_t*)_mtk_payload+4))<<24)
#define MTK_DIY14_NAV_HEIGHT(_mtk_payload) (int32_t)(*((uint8_t*)_mtk_payload+3+8)|*((uint8_t*)_mtk_payload+2+8)<<8|((int32_t)*((uint8_t*)_mtk_payload+1+8))<<16|((int32_t)*((uint8_t*)_mtk_payload+8))<<24)
#define MTK_DIY14_NAV_GSpeed(_mtk_payload) (int32_t)(*((uint8_t*)_mtk_payload+3+12)|*((uint8_t*)_mtk_payload+2+12)<<8|((int32_t)*((uint8_t*)_mtk_payload+1+12))<<16|((int32_t)*((uint8_t*)_mtk_payload+12))<<24)
#define MTK_DIY14_NAV_Heading(_mtk_payload) (int32_t)(*((uint8_t*)_mtk_payload+3+16)|*((uint8_t*)_mtk_payload+2+16)<<8|((int32_t)*((uint8_t*)_mtk_payload+1+16))<<16|((int32_t)*((uint8_t*)_mtk_payload+16))<<24)
#define MTK_DIY14_NAV_numSV(_mtk_payload) (uint8_t)(*((uint8_t*)_mtk_payload+20))
#define MTK_DIY14_NAV_GPSfix(_mtk_payload) (uint8_t)(*((uint8_t*)_mtk_payload+21))
#define MTK_DIY14_NAV_ITOW(_mtk_payload) (uint32_t)(*((uint8_t*)_mtk_payload+3+22)|*((uint8_t*)_mtk_payload+2+22)<<8|((uint32_t)*((uint8_t*)_mtk_payload+1+22))<<16|((uint32_t)*((uint8_t*)_mtk_payload+22))<<24)

#define MtkSend_DIY14_NAV(lat,lon,height,gspeed,heading,numsv,gpsfix,itow) { \
  MtkHeader(MTK_DIY14_ID, MTK_DIY14_NAV_ID, 26);\
  int32_t _lat = lat; MtkSend4ByAddr((uint8_t*)&_lat);\
  int32_t _lon = lon; MtkSend4ByAddr((uint8_t*)&_lon);\
  int32_t _height = height; MtkSend4ByAddr((uint8_t*)&_height);\
  int32_t _gspeed = gspeed; MtkSend4ByAddr((uint8_t*)&_gspeed);\
  int32_t _heading = heading; MtkSend4ByAddr((uint8_t*)&_heading);\
  uint8_t _numsv = numsv; MtkSend1ByAddr((uint8_t*)&_numsv);\
  uint8_t _gpsfix = gpsfix; MtkSend1ByAddr((uint8_t*)&_gpsfix);\
  uint32_t _itow = itow; MtkSend4ByAddr((uint8_t*)&_itow);\
  MtkTrailer();\
}

#define MTK_DIY14_NAV_LENGTH 26

#define MTK_DIY16_ID 0xD0

#define MTK_DIY16_NAV_ID 0xDD
#define MTK_DIY16_NAV_LAT(_mtk_payload) (int32_t)(*((uint8_t*)_mtk_payload+0)|*((uint8_t*)_mtk_payload+1+0)<<8|((int32_t)*((uint8_t*)_mtk_payload+2+0))<<16|((int32_t)*((uint8_t*)_mtk_payload+3+0))<<24)
#define MTK_DIY16_NAV_LON(_mtk_payload) (int32_t)(*((uint8_t*)_mtk_payload+4)|*((uint8_t*)_mtk_payload+1+4)<<8|((int32_t)*((uint8_t*)_mtk_payload+2+4))<<16|((int32_t)*((uint8_t*)_mtk_payload+3+4))<<24)
#define MTK_DIY16_NAV_HEIGHT(_mtk_payload) (int32_t)(*((uint8_t*)_mtk_payload+8)|*((uint8_t*)_mtk_payload+1+8)<<8|((int32_t)*((uint8_t*)_mtk_payload+2+8))<<16|((int32_t)*((uint8_t*)_mtk_payload+3+8))<<24)
#define MTK_DIY16_NAV_GSpeed(_mtk_payload) (int32_t)(*((uint8_t*)_mtk_payload+12)|*((uint8_t*)_mtk_payload+1+12)<<8|((int32_t)*((uint8_t*)_mtk_payload+2+12))<<16|((int32_t)*((uint8_t*)_mtk_payload+3+12))<<24)
#define MTK_DIY16_NAV_Heading(_mtk_payload) (int32_t)(*((uint8_t*)_mtk_payload+16)|*((uint8_t*)_mtk_payload+1+16)<<8|((int32_t)*((uint8_t*)_mtk_payload+2+16))<<16|((int32_t)*((uint8_t*)_mtk_payload+3+16))<<24)
#define MTK_DIY16_NAV_numSV(_mtk_payload) (uint8_t)(*((uint8_t*)_mtk_payload+20))
#define MTK_DIY16_NAV_GPSfix(_mtk_payload) (uint8_t)(*((uint8_t*)_mtk_payload+21))
#define MTK_DIY16_NAV_UTC_DATE(_mtk_payload) (uint32_t)(*((uint8_t*)_mtk_payload+22)|*((uint8_t*)_mtk_payload+1+22)<<8|((uint32_t)*((uint8_t*)_mtk_payload+2+22))<<16|((uint32_t)*((uint8_t*)_mtk_payload+3+22))<<24)
#define MTK_DIY16_NAV_UTC_TIME(_mtk_payload) (uint32_t)(*((uint8_t*)_mtk_payload+26)|*((uint8_t*)_mtk_payload+1+26)<<8|((uint32_t)*((uint8_t*)_mtk_payload+2+26))<<16|((uint32_t)*((uint8_t*)_mtk_payload+3+26))<<24)
#define MTK_DIY16_NAV_HDOP(_mtk_payload) (uint16_t)(*((uint8_t*)_mtk_payload+30)|*((uint8_t*)_mtk_payload+1+30)<<8)

#define MtkSend_DIY16_NAV(lat,lon,height,gspeed,heading,numsv,gpsfix,utc_date,utc_time,hdop) { \
  MtkHeader(MTK_DIY16_ID, MTK_DIY16_NAV_ID, 32);\
  int32_t _lat = lat; MtkSend4ByAddr((uint8_t*)&_lat);\
  int32_t _lon = lon; MtkSend4ByAddr((uint8_t*)&_lon);\
  int32_t _height = height; MtkSend4ByAddr((uint8_t*)&_height);\
  int32_t _gspeed = gspeed; MtkSend4ByAddr((uint8_t*)&_gspeed);\
  int32_t _heading = heading; MtkSend4ByAddr((uint8_t*)&_heading);\
  uint8_t _numsv = numsv; MtkSend1ByAddr((uint8_t*)&_numsv);\
  uint8_t _gpsfix = gpsfix; MtkSend1ByAddr((uint8_t*)&_gpsfix);\
  uint32_t _utc_date = utc_date; MtkSend4ByAddr((uint8_t*)&_utc_date);\
  uint32_t _utc_time = utc_time; MtkSend4ByAddr((uint8_t*)&_utc_time);\
  uint16_t _hdop = hdop; MtkSend2ByAddr((uint8_t*)&_hdop);\
  MtkTrailer();\
}

#define MTK_DIY16_NAV_LENGTH 32
