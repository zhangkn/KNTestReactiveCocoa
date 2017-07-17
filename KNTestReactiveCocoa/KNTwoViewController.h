//
//  KNTwoViewController.h
//  KNTestReactiveCocoa
//
//  Created by devzkn on 17/07/2017.
//  Copyright © 2017 hisun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <ReactiveCocoa/ReactiveCocoa.h>
@interface KNTwoViewController : UIViewController

@property (nonatomic, strong) RACSubject *delegateSignal;


@end
