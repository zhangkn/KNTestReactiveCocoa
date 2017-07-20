//
//  HSFiendsModel.m
//  20160329-qq好友列表
//
//  Created by devzkn on 3/29/16.
//  Copyright © 2016 hisun. All rights reserved.
//

#import "HSFiendsModel.h"

@implementation HSFiendsModel
@synthesize iconImage = _iconImage;




- (UIImage *)iconImage{
    if (nil == _iconImage) {
        _iconImage = [UIImage imageNamed:self.icon];
    }
    return _iconImage;
}



- (instancetype)initWithDictionary:(NSDictionary *)dict{
    //KVC
    self = [super init];//初始化父类属性
    if (self) {
        //初始化自身属性
        [self setValuesForKeysWithDictionary:dict];
    }
    return self;
}
+ (instancetype)friendsWithDictionary:(NSDictionary *)dict{
    return [[self alloc]initWithDictionary:dict];
}
/**
 字典数组转化为数据模型数组
 */
+ (NSArray *)fridensListWith:(NSArray *)dictArray{
    NSMutableArray *tmpArrayM = [NSMutableArray array];
    //解析plist
    for (NSDictionary *dict in  dictArray) {
        [tmpArrayM addObject:[self friendsWithDictionary:dict]];
    }
    return tmpArrayM;
}

@end
