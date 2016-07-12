//
//  x264Manager.h
//  AirCam
//
//  Created by chenlm on 11/1/14.
//  Copyright (c) 2014 Bob. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "x264.h"
#import <CoreMedia/CoreMedia.h>

@interface x264Manager : NSObject {
    x264_param_t * p264Param;
    x264_picture_t * p264Pic;
    x264_t *p264Handle;
    x264_nal_t  *p264Nal;
    FILE *fp;
    unsigned char sps[30];
    unsigned char pps[10];
}

- (void)initForX264WithWidth:(int)width height:(int)height;

- (void)initForFilePath;
//初始化编码后文件的保存路径

- (void)encoderToH264:(CMSampleBufferRef)sampleBuffer;

+(x264Manager*)getInstance;

- (void)stopEncoding;

@end
