//
//  ViewController.m
//  KNTestReactiveCocoa
//
//  Created by devzkn on 17/07/2017.
//  Copyright © 2017 hisun. All rights reserved.
//

#import "ViewController.h"
#import "KNTwoViewController.h"
//#import "ReactiveCocoa.h"

//@import ReactiveCocoa;

#import <ReactiveCocoa/ReactiveCocoa.h>
#import "KNTestRACTool.h"
#import "KNTestRACMethodTool.h"


@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
//    [KNTestRACTool testRACSignal ];
//    [KNTestRACTool testRACSubject];
//    [KNTestRACTool testRACReplaySubject];
//    [KNTestRACTool testRACSequence];// 字典转模型
//    RACCommand
//    [KNTestRACTool testRACCommand];//RACCommand简单使用
//    [KNTestRACTool testRACMulticastConnection];
    
    
    
}


- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event{
    [self TestDelegateUsingRACSubject:nil];

}

/**
 RACSubject替换代理

 */
- (void)TestDelegateUsingRACSubject:(id)sender {
    
    // 创建第二个控制器
    KNTwoViewController *twoVc = [[KNTwoViewController alloc] init];
    
    // 设置代理信号
    twoVc.delegateSignal = [RACSubject subject];
    
    // 订阅代理信号
    [twoVc.delegateSignal subscribeNext:^(id x) {
        
        NSLog(@"点击了通知按钮");
    }];
    
    // 跳转到第二个控制器
    [self presentViewController:twoVc animated:YES completion:nil];
    
}








@end
