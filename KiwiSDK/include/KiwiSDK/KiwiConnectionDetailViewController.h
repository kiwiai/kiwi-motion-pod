//
//  KiwiConnectionDetailViewController.h
//  KiwiSDK
//
//  Created by Kiwi Wearable Technologies Ltd. on 2014-04-15.
//  Copyright (c) 2014 Kiwi Wearable Technologies Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "KiwiSDK.h"


@interface KiwiConnectionDetailViewController : UIViewController <KiwiDataDelegate>

@property (strong, nonatomic) CBPeripheral* kiwiDevice;

- (void) updateDeviceStatusLabel;

- (IBAction)onConnectButtonTapped:(id)sender;
- (IBAction)onMonitorAccelToggled:(UISwitch*)sender;

@end
