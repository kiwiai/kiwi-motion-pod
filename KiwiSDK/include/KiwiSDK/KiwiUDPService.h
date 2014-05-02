//
//  KiwiUDPService.h
//  KiwiSDK
//
//  Created by Kiwi Wearable Technologies Ltd. on 2014-04-15.
//  Copyright (c) 2014 Kiwi Wearable Technologies Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CocoaAsyncSocket/AsyncUdpSocket.h>
#import <CoreMotion/CoreMotion.h>

@interface KiwiUDPService : NSObject <AsyncUdpSocketDelegate>

@property (strong, nonatomic) AsyncUdpSocket* socket;

+(id)sharedInstance;
- (instancetype) init;
- (void) connect;
- (void) sendData:(NSData*)data;
- (void) sendTestData;

- (NSData*) serverDataWithCharacteristicData:(NSData*)data;
- (NSData*) serverDataWithDeviceMotion:(CMDeviceMotion*)deviceMotion;

@end
