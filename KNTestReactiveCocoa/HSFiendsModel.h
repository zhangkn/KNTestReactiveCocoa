//
//  HSFiendsModel.h
//  20160329-qq好友列表
//
//  Created by devzkn on 3/29/16.
//  Copyright © 2016 hisun. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface HSFiendsModel : UIView
@property (nonatomic,copy) NSString *icon;
@property (nonatomic,strong,readonly) UIImage *iconImage;
@property (nonatomic,copy) NSString *intro;
@property (nonatomic,copy) NSString *name;
@property (nonatomic,assign,getter=isVip) BOOL vip;//getter=isVip 


//定义初始化方法 KVC的使用
- (instancetype) initWithDictionary:(NSDictionary *) dict;
+ (instancetype) friendsWithDictionary:(NSDictionary *) dict;

/**
 提供类方法，返回数据模型数组
 */
+ (NSArray *) fridensListWith: (NSArray *)dictArray;


@end
