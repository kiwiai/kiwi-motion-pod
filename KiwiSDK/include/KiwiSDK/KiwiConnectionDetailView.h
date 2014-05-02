//
//  KiwiConnectionDetailView.h
//  KiwiSDK
//
//  Created by Kiwi Wearable Technologies Ltd. on 2014-04-15.
//  Copyright (c) 2014 Kiwi Wearable Technologies Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface KiwiConnectionDetailView : UIView

@property (strong, nonatomic) IBOutlet UILabel* deviceNameLabel;
@property (strong, nonatomic) IBOutlet UILabel* connectionStatusLabel;
@property (strong, nonatomic) IBOutlet UIButton* connectButton;
@property (strong, nonatomic) IBOutlet UISwitch* accelMonitoredSwitch;
@property (strong, nonatomic) IBOutlet UILabel* accelDataLabel;
@property (strong, nonatomic) IBOutlet UITextField* accelDataTextField;

@end
