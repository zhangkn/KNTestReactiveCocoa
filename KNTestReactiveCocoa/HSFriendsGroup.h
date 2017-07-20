//
//  HSFriendsGroup.h
//  20160329-qq好友列表
//
//  Created by devzkn on 3/29/16.
//  Copyright © 2016 hisun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "HSFiendsModel.h"

@interface HSFriendsGroup : UIView
@property (nonatomic,copy) NSString *name;//section‘s name
@property (nonatomic,assign) int online;//在线人数
@property (nonatomic,strong,readonly) UIImage *buddyHeaderArowImage;
@property (nonatomic,strong) NSArray *friendsList;//使用setter方法进行赋值
@property (nonatomic,assign) BOOL isOpen;//判断是否张开或者合上cell
/**
 提供类方法，返回数据模型数组
 */
+ (NSArray *) friendsGroups;
//定义初始化方法 KVC的使用
- (instancetype) initWithDictionary:(NSDictionary *) dict;
+ (instancetype) friendsGroupWithDictionary:(NSDictionary *) dict;


@end
