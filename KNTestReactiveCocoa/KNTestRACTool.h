//
//  KNTestRACTool.h
//  KNTestReactiveCocoa
//
//  Created by devzkn on 17/07/2017.
//  Copyright © 2017 hisun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <ReactiveCocoa/ReactiveCocoa.h>
#import "HSFriendsGroup.h"

@interface KNTestRACTool : NSObject


/**
 // RACMulticastConnection使用步骤:
 // 1.创建信号 + (RACSignal *)createSignal:(RACDisposable * (^)(id<RACSubscriber> subscriber))didSubscribe
 // 2.创建连接 RACMulticastConnection *connect = [signal publish];
 // 3.订阅信号,注意：订阅的不在是之前的信号，而是连接的信号。 [connect.signal subscribeNext:nextBlock]
 // 4.连接 [connect connect]
 
 使用注意:RACMulticastConnection通过RACSignal的-publish或者-muticast:方法创建.
 
 使用场景：当一个信号，被多次订阅时，为了保证创建信号时，避免多次调用创建信号中的block，造成副作用，可以使用这个类处理。

 */
+ (void)testRACMulticastConnection;

/**
 使用场景:监听按钮点击，网络请求
 // 一、RACCommand使用步骤:
 // 1.创建命令 initWithSignalBlock:(RACSignal * (^)(id input))signalBlock
 // 2.在signalBlock中，创建RACSignal，并且作为signalBlock的返回值
 // 3.执行命令 - (RACSignal *)execute:(id)input
 
 
 */
+ (void)testRACCommand;


/**
 .字典转模型
 RACSequence和RACTuple简单使用
 
 */
+ (void)testRACSequence;


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
