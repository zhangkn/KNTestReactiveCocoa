//
//  KNTestRACMethodTool.h
//  KNTestReactiveCocoa
//
//  Created by devzkn on 20/07/2017.
//  Copyright © 2017 hisun. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
  iOS Reactive Cocoa的常见用法
 
.1 代替代理:
 
 rac_signalForSelector：用于替代代理。
 
 案例一：
 // 需求：自定义redView,监听红色view中按钮点击
 // 之前都是需要通过代理监听，给红色View添加一个代理属性，点击按钮的时候，通知代理做事情
 // rac_signalForSelector:把调用某个对象的方法的信息转换成信号，就要调用这个方法，就会发送信号。
 // 这里表示只要redV调用btnClick:,就会发出信号，订阅就好了。
 [[redV rac_signalForSelector:@selector(btnClick:)] subscribeNext:^(id x) {
 NSLog(@"点击红色按钮");
 }];
 
 案例二：nameText的输入字符时，输入回撤或者点击键盘的回车键使passWordText变为第一响应者（即输入光标移动到passWordText处）
 - (void)delegateDemo {
 
 @weakify(self)
 // 1. 定义代理
 self.proxy = [[RACDelegateProxy alloc] initWithProtocol:@protocol(UITextFieldDelegate)];
 // 2. 代理去注册文本框的监听方法
 [[self.proxy rac_signalForSelector:@selector(textFieldShouldReturn:)]
 subscribeNext:^(id x) {
 @strongify(self)
 if (self.nameText.hasText) {
 [self.passWordText becomeFirstResponder];
 }
 }];
 self.nameText.delegate = (id<UITextFieldDelegate>)self.proxy;
 }
 
 
.2 代替KVO :
 
 案例一：
  * 为了测试此函数，增加了一个Person类 && 一个Label；点击屏幕则会等改Lable的值

 #pragma -mark KVO 监听
 - (void)demoKvo {
 
 @weakify(self)
 [RACObserve(self.person, name)
 subscribeNext:^(id x) {
 @strongify(self)
 self.nameLabel.text = x;
 }];
 }
 
 案例二：
 
 
 rac_valuesAndChangesForKeyPath：用于监听某个对象的属性改变。
 
 // 2.KVO
 // 把监听redV的center属性改变转换成信号，只要值改变就会发送信号
 // observer:可以传入nil
 [[redV rac_valuesAndChangesForKeyPath:@"center" options:NSKeyValueObservingOptionNew observer:nil] subscribeNext:^(id x) {
 
 NSLog(@"%@",x);
 
 }];
 
 
.3 监听事件:
 
 rac_signalForControlEvents：用于监听某个事件。
 
  * 验证此函数：当loginButton可以点击时，点击button输出person的属性，实现监控的效果
 - (void)buttonDemo {
 @weakify(self);
 [[self.loginButton rac_signalForControlEvents:UIControlEventTouchUpInside]
 subscribeNext:^(id x) {
 @strongify(self);
 NSLog(@"person.name:  %@    person.password:  %@",self.person.name,self.person.password);
 }
 ];
 }
 
 
 
.4 代替通知:
 
 rac_addObserverForName:用于监听某个通知。
 
  * 验证此函数：点击textFile时，系统键盘会发送通知，打印出通知的内容

 - (void)notificationDemo {
 [[[NSNotificationCenter defaultCenter] rac_addObserverForName:UIKeyboardWillChangeFrameNotification object:nil]
 subscribeNext:^(id x) {
 NSLog(@"notificationDemo : %@", x);
 }
 ];
 }

 
 
 
 
.5 监听文本框文字改变:
 
 rac_textSignal:只要文本框发出改变就会发出这个信号。
 
 
  * 、为了测试此函数，增加了一个nameText；监听文本框的输入内容，并设置为self.person.name

 
 
 - (void)demoTextField {
 
 @weakify(self);
 [[self.nameText rac_textSignal]
 subscribeNext:^(id x) {
 @strongify(self);
 NSLog(@"%@",x);
 self.person.name = x;
 }];
 }

  * 、为了验证此函数，增加了一个passwordText和一个Button，监测nameText和passwordText
 
 - (void)textFileCombination {
 
 id signals = @[[self.nameText rac_textSignal],[self.passWordText rac_textSignal]];
 
 @weakify(self);
 [[RACSignal
 combineLatest:signals]
 subscribeNext:^(RACTuple *x) {
 
 @strongify(self);
 NSString *name = [x first];
 NSString *password = [x second];
 
 if (name.length > 0 && password.length > 0) {
 
 self.loginButton.enabled = YES;
 self.person.name = name;
 self.person.password = password;
 
 } else  {
 self.loginButton.enabled = NO;
 
 }
 }];
 
 }

 
 
 
.6 处理当界面有多次请求时，需要都获取到数据时，才能展示界面
 

     // 使用注意：N个信号，参数一的方法的参数列表中就有对应N个参数，每个参数对应信号返回的数据。
 
 
 
 .6 处理当界面有多次请求时，需要都获取到数据时，才能展示界面（可以采用GCD的组dispatch_group_notify 函数实现）http://blog.csdn.net/z929118967/article/details/74292418

 rac_liftSelector:withSignalsFromArray:Signals:当传入的Signals(信号数组)，每一个signal都至少sendNext过一次，就会去触发第一个selector参数的方法。
异步处理，等异步任务都结束之后，再执行特定的操作
 
 
 
 
 // 6.处理多个请求，都返回结果的时候，统一做处理.
 RACSignal *request1 = [RACSignal createSignal:^RACDisposable *(id<RACSubscriber> subscriber) {
 
 // 发送请求1
 [subscriber sendNext:@"发送请求1"];
 return nil;
 }];
 
 RACSignal *request2 = [RACSignal createSignal:^RACDisposable *(id<RACSubscriber> subscriber) {
 // 发送请求2
 [subscriber sendNext:@"发送请求2"];
 return nil;
 }];
 
 // 使用注意：N个信号，参数一的方法的参数列表中就有对应N个参数，每个参数对应信号返回的数据。
 [self rac_liftSelector:@selector(updateUIWithR1:r2:) withSignalsFromArray:@[request1,request2]];
 
 
 }
 // 更新UI
 - (void)updateUIWithR1:(id)data r2:(id)data1
 {
 NSLog(@"更新UI%@  %@",data,data1);
 }
 
 
 
 
 
 
 
 
 
 */
@interface KNTestRACMethodTool : NSObject



















@end
