//
//  KiwiMotionService.h
//  KiwiSDK
//
//  Created by Kiwi Wearable Technologies Ltd. on 2014-04-26.
//  Copyright (c) 2014 Kiwi Wearable Technologies Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMotion/CoreMotion.h>

@interface KiwiMotionService : NSObject

@property (strong, nonatomic) CMMotionManager* motionManager;
@property (strong, nonatomic) CMDeviceMotion *referenceDeviceMotion;

@property (nonatomic) NSUInteger rollingMotionDataSampleSize;
@property (strong, nonatomic) NSMutableArray* rollingMotionDataArray;

+ (id)sharedInstance;
- (instancetype) init;

- (void) startMotionDetection;
- (void) stopMotionDetection;

@end
