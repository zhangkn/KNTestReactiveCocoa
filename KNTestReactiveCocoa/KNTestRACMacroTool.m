
//
//  KNTestRACMacroTool.m
//  KNTestReactiveCocoa
//
//  Created by devzkn on 20/07/2017.
//  Copyright © 2017 hisun. All rights reserved.
//

#import "KNTestRACMacroTool.h"

/**
 ReactiveCocoa常见宏

 */
@implementation KNTestRACMacroTool


//macro




//1、RAC(TARGET, [KEYPATH, [NIL_VALUE]]):用于给某个对象的某个属性绑定。

// 只要文本框文字改变，就会修改label的文字
//RAC(self.labelView,text) = _textField.rac_textSignal;


//2、RACObserve(self, name):监听某个对象的某个属性,返回的是信号。



//[RACObserve(self.view, center) subscribeNext:^(id x) {
//    
//    NSLog(@"%@",x);
//}];

//@weakify(Obj)和@strongify(Obj),一般两个都是配套使用,在主头文件(ReactiveCocoa.h)中并没有导入，需要自己手动导入RACEXTScope.h才可以使用。但是每次导入都非常麻烦，只需要在主头文件自己导入就好了。


/**
3、
RACTuplePack：把数据包装成RACTuple（元组类）
 // 把参数中的数据包装成元组
 RACTuple *tuple = RACTuplePack(@10,@20);
 
 
 
 
 
 
*/


/**4.RACTupleUnpack：把RACTuple（元组类）解包成对应的数据。

 // 把参数中的数据包装成元组
 RACTuple *tuple = RACTuplePack(@"xmg",@20);
 
 // 解包元组，会把元组的值，按顺序给参数里面的变量赋值
 // name = @"xmg" age = @20
 RACTupleUnpack(NSString *name,NSNumber *age) = tuple;
 
 */






@end
