//
//  KNTestRACTool.h
//  KNTestReactiveCocoa
//
//  Created by devzkn on 17/07/2017.
//  Copyright © 2017 hisun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <ReactiveCocoa/ReactiveCocoa.h>
@interface KNTestRACTool : NSObject


/**
 // RACSignal使用步骤：
 // 1.创建信号 + (RACSignal *)createSignal:(RACDisposable * (^)(id<RACSubscriber> subscriber))didSubscribe
 // 2.订阅信号,才会激活信号. - (RACDisposable *)subscribeNext:(void (^)(id x))nextBlock
 // 3.发送信号 - (void)sendNext:(id)value
 */
+ (void) testRACSignal;

/**
 // RACSubject使用步骤
 // 1.创建信号 [RACSubject subject]，跟RACSiganl不一样，创建信号时没有block。
 // 2.订阅信号 - (RACDisposable *)subscribeNext:(void (^)(id x))nextBlock
 // 3.发送信号 sendNext:(id)value
 */
+ (void) testRACSubject;


// RACReplaySubject使用步骤:
// 1.创建信号 [RACSubject subject]，跟RACSiganl不一样，创建信号时没有block。
// 2.可以先订阅信号，也可以先发送信号。
// 2.1 订阅信号 - (RACDisposable *)subscribeNext:(void (^)(id x))nextBlock
// 2.2 发送信号 sendNext:(id)value
+ (void)testRACReplaySubject;




@end
