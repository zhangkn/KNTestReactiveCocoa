//
//  HSFriendsGroup.m
//  20160329-qq好友列表
//
//  Created by devzkn on 3/29/16.
//  Copyright © 2016 hisun. All rights reserved.
//

#import "HSFriendsGroup.h"

@implementation HSFriendsGroup
@synthesize buddyHeaderArowImage = _buddyHeaderArowImage;

- (UIImage *)buddyHeaderArowImage{
    if (nil == _buddyHeaderArowImage) {
        _buddyHeaderArowImage = [UIImage imageNamed:@"buddy_header_arrow"];
    }
    return _buddyHeaderArowImage;
}
- (instancetype)initWithDictionary:(NSDictionary *)dict{
    //KVC
    self = [super init];//初始化父类属性
    if (self) {
        //初始化自身属性
        [self setValue:dict[@"name"] forKey:@"name"];
        [self setValue:dict[@"online"] forKey:@"online"];
        [self setFriendsList:[HSFiendsModel fridensListWith:dict[@"friends"]]];//利用setter方法设置cell数组
    }
    return self;
}
/**
 字典转模型
 */
+ (instancetype)friendsGroupWithDictionary:(NSDictionary *)dict{
    return [[self alloc]initWithDictionary:dict];
}

+ (NSArray *)friendsGroups{
    NSMutableArray *tmpArrayM = [NSMutableArray array];
    //解析plist
    NSString *path = [[NSBundle mainBundle] pathForResource:@"friends" ofType:@"plist"];
    NSArray *arrayDict = [NSArray arrayWithContentsOfFile:path];
    for (NSDictionary *dict in  arrayDict) {
        [tmpArrayM addObject:[self friendsGroupWithDictionary:dict]];
    }
    return tmpArrayM;
}



@end
