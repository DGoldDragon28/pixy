/*
 * PixyJNI.cpp
 *
 *  Created on: Jan 18, 2017
 *      Author: Duncan
 */
#include <jni_md.h>
#include "org_usfirst_frc_team1719_pixyjni_PixyJNI.h"
#include "pixy.h"
#include <jni_md.h>

JNIEXPORT jint JNICALL Java_org_usfirst_frc_team1719_pixyjni_PixyJNI_init
  (JNIEnv * env, jobject obj){
	return pixy_init();
}

JNIEXPORT jint JNICALL Java_org_usfirst_frc_team1719_pixyjni_PixyJNI_blocksAreNew
  (JNIEnv * env, jobject obj){
	return pixy_blocks_are_new();
}

JNIEXPORT jint JNICALL Java_org_usfirst_frc_team1719_pixyjni_PixyJNI_getAutoExposureCompensation
  (JNIEnv * env, jobject obj){
	return pixy_cam_get_auto_exposure_compensation();
}

JNIEXPORT jint JNICALL Java_org_usfirst_frc_team1719_pixyjni_PixyJNI_getAutoWhiteBalance
  (JNIEnv * env, jobject obj){
	return pixy_cam_get_auto_white_balance();
}

JNIEXPORT jint JNICALL Java_org_usfirst_frc_team1719_pixyjni_PixyJNI_getBrightness
  (JNIEnv * env, jobject obj){
	return pixy_cam_get_brightness();
}

JNIEXPORT jint JNICALL Java_org_usfirst_frc_team1719_pixyjni_PixyJNI_getExposureCompensastion
  (JNIEnv * env, jobject obj, jobject gain, jobject compensation){
	uint8_t* cgain = malloc(sizeof(int));
	uint16_t* ccomp = malloc(sizeof(int));
	int ret = pixy_cam_get_exposure_compensation(cgain, ccomp);
	jfieldID val = env->GetFieldID(env->GetObjectClass(gain), "value", "I");
	env->SetIntField(gain, val, (jint) *cgain);
	env->SetIntField(compensation, val, (jint) *ccomp);
	free(cgain);
	free(ccomp);
	return ret;
}

JNIEXPORT jint JNICALL Java_org_usfirst_frc_team1719_pixyjni_PixyJNI_getWhiteBalanceValue
  (JNIEnv * env, jobject obj){
	return pixy_cam_get_white_balance_value();
}

JNIEXPORT jint JNICALL Java_org_usfirst_frc_team1719_pixyjni_PixyJNI_setAutoExposureCompensation
  (JNIEnv * env, jobject obj, jboolean enable){
	return pixy_cam_set_auto_exposure_compensation(enable);
}

JNIEXPORT jint JNICALL Java_org_usfirst_frc_team1719_pixyjni_PixyJNI_setAutoWhiteBalance
  (JNIEnv * env, jobject obj, jboolean enable){
	return pixy_cam_set_auto_white_balance(enable);
}

JNIEXPORT jint JNICALL Java_org_usfirst_frc_team1719_pixyjni_PixyJNI_setBrightness
  (JNIEnv * env, jobject obj, jint brightness){
	return pixy_cam_set_brightness((uint8_t) (brightness & 0x000000FF));
}

JNIEXPORT jint JNICALL Java_org_usfirst_frc_team1719_pixyjni_PixyJNI_setExposureCompensation
  (JNIEnv * env, jobject obj, jint gain, jint comp){
	return pixy_cam_set_exposure_compensation((uint8_t)(gain & 0x000000FF),(uint16_t)(comp & 0x0000FFFF));
}

JNIEXPORT jint JNICALL Java_org_usfirst_frc_team1719_pixyjni_PixyJNI_setWhiteBalanceValue
  (JNIEnv * env, jobject obj, jint r, jint g, jint b){
	return pixy_cam_set_white_balance_value((uint8_t)(r & 0x000000FF),(uint8_t)(g & 0x000000FF),(uint8_t)(b & 0x000000FF));
}

JNIEXPORT void JNICALL Java_org_usfirst_frc_team1719_pixyjni_PixyJNI_close
  (JNIEnv * env, jobject obj){
	pixy_close();
}

JNIEXPORT jint JNICALL Java_org_usfirst_frc_team1719_pixyjni_PixyJNI_command
  (JNIEnv * env, jobject obj, jstring cmd, jobjectArray objs){
	return -1; // NOT SUPPORTED YET
	const char* command = env->GetStringUTFChars(cmd, 0);
	// TODO
	env->ReleaseStringUTFChars(cmd, command);
}

JNIEXPORT jint JNICALL Java_org_usfirst_frc_team1719_pixyjni_PixyJNI_getBlocks
  (JNIEnv * env, jobject obj, jint max, jobjectArray jblocks){
	Block * cblocks = malloc((size_t) max * sizeof(Block));
	int ret = pixy_get_blocks((uint16_t) max, cblocks);
	jclass clazz = env->FindClass("org/usfirst/frc/team1719/pixyjni/Block");
	jmethodID constructor = env->GetMethodID(clazz, "<init>", "(IIIIIII)V");
	for(int i = 0; i < ret; i++) {
		Block* cblock = &cblocks[i];
		jobject jblock = env->NewObject(clazz, constructor, cblock->type, cblock->signature,
				cblock->x, cblock->y, cblock->width, cblock->height, cblock->angle);
		env->SetObjectArrayElement(jblocks, (jsize) i, jblock);
	}
	free(cblocks);
	return ret;
}

JNIEXPORT jint JNICALL Java_org_usfirst_frc_team1719_pixyjni_PixyJNI_getFirmwareVersion
  (JNIEnv * env, jobject obj, jobject maj, jobject min, jobject bld){
	uint16_t* major = malloc(sizeof(int));
	uint16_t* minor = malloc(sizeof(int));
	uint16_t* build = malloc(sizeof(int));
	int ret = pixy_get_firmware_version(major, minor, build);
	jfieldID val = env->GetFieldID(env->GetObjectClass(maj), "value", "I");
	env->SetIntField(maj, val, (jint) *major);
	env->SetIntField(min, val, (jint) *minor);
	env->SetIntField(bld, val, (jint) *build);
	free(major);
	free(minor);
	free(build);
	return ret;
}

JNIEXPORT jint JNICALL Java_org_usfirst_frc_team1719_pixyjni_PixyJNI_ledGetMaxCurrent
  (JNIEnv * env, jobject obj){
	return pixy_led_get_max_current();
}

JNIEXPORT jint JNICALL Java_org_usfirst_frc_team1719_pixyjni_PixyJNI_ledSetMaxCurrent
  (JNIEnv * env, jobject obj, jint current){
	return pixy_led_set_max_current((uint32_t) current);
}

JNIEXPORT jint JNICALL Java_org_usfirst_frc_team1719_pixyjni_PixyJNI_ledSetRGB
  (JNIEnv * env, jobject obj, jint r, jint g, jint b){
	return pixy_led_set_RGB((uint8_t)(r & 0x000000FF),(uint8_t)(g & 0x000000FF),(uint8_t)(b & 0x000000FF));
}
