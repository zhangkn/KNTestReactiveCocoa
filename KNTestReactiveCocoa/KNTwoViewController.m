//
//  KNTwoViewController.m
//  KNTestReactiveCocoa
//
//  Created by devzkn on 17/07/2017.
//  Copyright © 2017 hisun. All rights reserved.
//

#import "KNTwoViewController.h"

/**
 // 需求:
 // 1.给当前控制器添加一个按钮，modal到另一个控制器界面
 // 2.另一个控制器view中有个按钮，点击按钮，通知当前控制器
 
 步骤一：在第二个控制器.h，添加一个RACSubject代替代理。

 步骤二：监听控制器按钮点击

 步骤三：在第一个控制器中，给第二个控制器的代理信号赋值，并且

 
 
 */
@interface KNTwoViewController ()

@end

@implementation KNTwoViewController

/**
 步骤二：监听控制器按钮点击

 */
- (IBAction)clickBtn:(id)sender {
    
    // 通知第一个控制器，告诉它，按钮被点了
    
    // 通知代理
    // 判断代理信号是否有值
    if (self.delegateSignal) {
        // 有值，才需要通知
        [self.delegateSignal sendNext:nil];
    }
    
   
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
