//
//  AVUtils.h
//  paas
//
//  Created by Zhu Zeng on 2/27/13.
//  Copyright (c) 2013 AVOS. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AVConstants.h"

#define classNameTag @"className"

@class AVObject;

@interface AVUtils : NSObject

+(void)warnMainThreadIfNecessary;

+(AVObject *)avObjectFromDictionary:(NSDictionary *)src
                          className:(NSString *)className;
+(void)copyPropertiesFrom:(NSObject *)src
                 toObject:(NSObject *)target;
+(void)copyPropertiesFromDictionary:(NSDictionary *)src
                           toObject:(AVObject *)target;
+(void)copyPropertiesFromDictionary:(NSDictionary *)src
                         toNSObject:(NSObject *)target;
+(NSMutableDictionary *)dictionaryFromObject:(NSObject *)target;

+ (BOOL)array:(NSArray *)array containObjectById:(NSString *)objectId;

+(NSString *)stringFromDate:(NSDate *)date;
+(NSDictionary *)dictionaryFromDate:(NSDate *)date;
+(NSDate *)dateFromDictionary:(NSDictionary *)dict;

+(NSDictionary *)dictionaryFromData:(NSData *)data;
+(NSData *)dataFromDictionary:(NSDictionary *)dict;

+(NSString *)batchPath;
+(NSString *)batchSavePath;
+(NSMutableDictionary *)serverDataDictionary:(NSDictionary *)dict;

+(BOOL)isUserClass:(NSString *)className;
+(BOOL)isInstallationClass:(NSString *)className;

+(NSString *)objectPath:(NSString *)objectClass
               objectId:(NSString *)objectId;

+(NSString *)jsonString:(NSDictionary *)dictionary;

+(void)performSelectorIfCould:(id)target
                     selector:(SEL)selector
                       object:(id)arg1
                       object:(id)arg2;

+ (NSString *)generateUUID;

#pragma mark - Block
/**
 typedef void (^PFBooleanResultBlock)(BOOL succeeded, NSError *error);
 typedef void (^PFIntegerResultBlock)(int number, NSError *error);
 typedef void (^PFArrayResultBlock)(NSArray *objects, NSError *error);
 typedef void (^PFObjectResultBlock)(AVObject *object, NSError *error);
 typedef void (^PFSetResultBlock)(NSSet *channels, NSError *error);
 typedef void (^PFUserResultBlock)(AVUser *user, NSError *error);
 typedef void (^PFDataResultBlock)(NSData *data, NSError *error);
 typedef void (^PFDataStreamResultBlock)(NSInputStream *stream, NSError *error);
 typedef void (^PFStringResultBlock)(NSString *string, NSError *error);
 typedef void (^PFIdResultBlock)(id object, NSError *error);
 typedef void (^PFProgressBlock)(int percentDone);
 */
+ (void)callBooleanResultBlock:(PFBooleanResultBlock)block
                         error:(NSError *)error;

+ (void)callIntegerResultBlock:(PFIntegerResultBlock)block
                        number:(int)number
                         error:(NSError *)error;

+ (void)callArrayResultBlock:(PFArrayResultBlock)block
                       array:(NSArray *)array
                       error:(NSError *)error;

+ (void)callObjectResultBlock:(PFObjectResultBlock)block
                       object:(AVObject *)object
                        error:(NSError *)error;

+ (void)callUserResultBlock:(PFUserResultBlock)block
                       user:(AVUser *)user
                      error:(NSError *)error;

+ (void)callIdResultBlock:(PFIdResultBlock)block
                   object:(id)object
                    error:(NSError *)error;

+ (void)callProgressBlock:(PFProgressBlock)block
                  percent:(int)percentDone;


+(void)callSetResultBlock:(PFSetResultBlock)block
                      set:(NSSet *)set
                    error:(NSError *)error;



#pragma mark - Data for server
+ (NSMutableDictionary *)parsedDictionary:(NSMutableDictionary *)dic;
+ (id)parsedObject:(id)obj;

#pragma mark - Data from server
// response: Dictionary/Array or Simple Objects like String/Number(all from json)
+ (id)processedResultFromId:(id)response;
+ (id)processedResultFromArray:(NSArray *)array;
+ (id)processedResultFromDic:(NSDictionary *)dic;

#pragma mark - String Util
+ (NSString *)MIMEType:(NSString *)filePathOrName;
@end



