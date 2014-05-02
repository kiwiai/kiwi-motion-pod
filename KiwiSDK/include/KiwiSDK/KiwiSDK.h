//
//  KiwiSDK.h
//  KiwiSDK
//
//  Created by Kiwi Wearable Technologies Ltd. on 2014-03-22.
//  Copyright (c) 2014 Kiwi Wearable Technologies Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

#undef weak_delegate
#undef __weak_delegate
#if __has_feature(objc_arc) && __has_feature(objc_arc_weak) && \
(!(defined __MAC_OS_X_VERSION_MIN_REQUIRED) || \
__MAC_OS_X_VERSION_MIN_REQUIRED >= __MAC_10_8)
#define weak_delegate weak
#else
#define weak_delegate unsafe_unretained
#endif

@protocol KiwiDataDelegate;

@interface KiwiSDK : NSObject <CBCentralManagerDelegate, CBPeripheralDelegate>

@property (nonatomic, weak_delegate) IBOutlet id<KiwiDataDelegate> dataDelegate;

@property (strong, nonatomic) CBCentralManager* cbCentralManager;

@property (strong, nonatomic) NSString* kiwiDeviceName;
@property (strong, nonatomic) NSMutableArray* kiwiDevices;
@property (strong, nonatomic) CBPeripheral* connectedKiwiPeripheral;

@property (strong, nonatomic) CBCharacteristic* serialPortInputCharacteristic;
@property (strong, nonatomic) CBCharacteristic* serialPortOutputCharacteristic;

@property (strong, nonatomic) CBCharacteristic* sensorCharacteristic;
@property (strong, nonatomic) CBCharacteristic* sensorConfigCharacteristic;

@property (strong, nonatomic) NSDictionary* sensorData;


#pragma mark - Singleton Methods


+ (id)sharedInstance;
- (instancetype) init;


#pragma  mark - Kiwi Convenience Stats Methods

- (void) pushKiwiConnectionViewController;
- (void) pushKiwiMotionViewController;
- (NSUInteger) numDetectedKiwis;
- (CBPeripheral*) kiwiAtIndex:(NSUInteger)index;


#pragma mark - Bluetooth Search Methods

- (void) startScanning;
- (void) stopScanning;


#pragma mark - Kiwi Connection Methods


- (void) connectToKiwiWithName:(NSString*)kiwiShortName;
- (NSString*) fullKiwiDeviceName:(NSString*)kiwiShortName;
- (void) connectToPeripheral:(CBPeripheral*)kiwiPeripheral;
- (BOOL) isKiwiDevice:(CBPeripheral*)cbPeripheral;


#pragma mark - CBCentralManagerDelegate Methods

- (void)centralManager:(CBCentralManager *)central didDiscoverPeripheral:(CBPeripheral *)peripheral advertisementData:(NSDictionary*) advertisementData RSSI:(NSNumber *)RSSI;


#pragma mark - CBPeripheralDelegate

- (void)centralManager:(CBCentralManager *)central didConnectPeripheral:(CBPeripheral *)peripheral;
- (void)peripheral:(CBPeripheral *)peripheral didDiscoverServices:(NSError *)error;
- (void)peripheral:(CBPeripheral *)peripheral didDiscoverCharacteristicsForService:(CBService *)service error:(NSError *)error;
- (void)peripheral:(CBPeripheral *)peripheral didUpdateNotificationStateForCharacteristic:(CBCharacteristic *)characteristic error:(NSError *)error;
- (void)peripheral:(CBPeripheral *)peripheral didUpdateValueForCharacteristic:(CBCharacteristic *)characteristic error:(NSError *)error;


#pragma mark - Kiwi Configuration Methods

- (void) startSensorOutputForPeripheral:(CBPeripheral*)kiwiDevice;
- (void) stopSensorOutputForPeripheral:(CBPeripheral*)kiwiDevice;
- (void) writeStartDataToCharacteristic:(CBCharacteristic*)characteristic;
- (void) writeEndDataToCharacteristic:(CBCharacteristic*)characteristic;
- (NSDictionary*) sensorDictForData:(NSData*)data;


#pragma mark - Motion Services


- (void) startMotionServices;
- (void) stopMotionServices;
- (void) addSoftTapObserver:(id)object withSelector:(SEL)selector;
- (void) addWaveObserver:(id)object withSelector:(SEL)selector;
- (void) addKnockObserver:(id)object withSelector:(SEL)selector;


@end

#pragma mark - KiwiDataSourceDelegate

@protocol KiwiDataDelegate <NSObject>

- (void) peripheral:(CBPeripheral *)peripheral didUpdateData:(NSDictionary*)data;

@optional
@end