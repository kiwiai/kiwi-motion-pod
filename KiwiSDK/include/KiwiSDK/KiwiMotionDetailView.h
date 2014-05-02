//
//  KiwiMotionDetailView.h
//  KiwiSDK
//
//  Created by Benjamin Graner on 2014-04-27.
//  Copyright (c) 2014 Nota Bene Studios. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface KiwiMotionDetailView : UIView

@property (strong, nonatomic) IBOutlet UIButton* startMotionDetectionButton;
@property (strong, nonatomic) IBOutlet UIButton* stopMotinoDetectionButton;
@property (strong, nonatomic) IBOutlet UILabel* gestureLabel;

@end
