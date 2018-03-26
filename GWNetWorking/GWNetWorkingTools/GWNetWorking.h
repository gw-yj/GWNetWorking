//
//  GWNetWorking.h
//  gw_test
//
//  Created by gw on 2018/3/23.
//  Copyright © 2018年 gw. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    POST_GW = 0,
    GET_GW,
    PUT_GW,
    DELETE_GW
} HTTPRequestType_GW;

@interface GWNetWorking : NSObject

@property (readonly,strong, nonatomic) NSMutableArray *taskArray;

+ (instancetype)shareGWNetWorking;


/**
 不带进度

 @param taskID 请求url
 @param param 参数
 @param method 方式
 @param success 成功
 @param failure 失败
 */
+ (void)request:(NSString*)taskID
      WithParam:(id)param
     withMethod:(HTTPRequestType_GW)method
        success:(void(^)(id result))success
        failure:(void(^)(NSError *erro))failure;


/**
 带进度条

 @param taskID 请求url
 @param param 参数
 @param method 方式
 @param uploadFileProgress 进度
 @param success 成功
 @param failure 失败
 */
+ (void)request:(NSString*)taskID
      WithParam:(id)param
     withMethod:(HTTPRequestType_GW)method
    uploadFileProgress:(void(^)(NSProgress *uploadProgress))uploadFileProgress
        success:(void(^)(id result))success
        failure:(void(^)(NSError *erro))failure;




/**
 图片上传

 @param taskID 请求url
 @param param 参数
 @param Exparam 图片参数
 @param method 方式
 @param uploadFileProgress 进度
 @param success 成功
 @param failure 失败
 */
+ (void)request:(NSString*)taskID
      WithParam:(NSDictionary*)param
    withExParam:(NSDictionary*)Exparam
     withMethod:(HTTPRequestType_GW)method
uploadFileProgress:(void(^)(NSProgress *uploadProgress))uploadFileProgress
        success:(void (^)(id result))success
        failure:(void (^)(NSError* erro))failure;



/**
 上传音频文件

 @param taskID 请求url
 @param param 参数
 @param Exparam 音频参数
 @param method 方式
 @param uploadFileProgress 进度
 @param success 成功
 @param failure 失败
 */
+ (void)requestSoundFileRequest:(NSString*)taskID
                      WithParam:(NSDictionary *)param
                    withExParam:(NSDictionary*)Exparam
                     withMethod:(HTTPRequestType_GW)method
             uploadFileProgress:(void(^)(NSProgress *uploadProgress))uploadFileProgress
                        success:(void(^)(id result))success
                        failure:(void(^)(NSError *erro))failure;



/**
 下载文件

 @param URLString 请求url
 @param param 参数
 @param method 方式
 @param downloadFileProgress 下载进度
 @param setupFilePath 保存路径
 @param downloadCompletionHandler 完成
 */
+ (void)requestDownloadFileWithURLString:(NSString *)URLString
                               WithParam:(NSDictionary *)param
                              withMethod:(HTTPRequestType_GW)method
                    downloadFileProgress:(void(^)(NSProgress *downloadProgress))downloadFileProgress
                           setupFilePath:(NSURL*(^)(NSURLResponse *response))setupFilePath
               downloadCompletionHandler:(void (^)(NSURL *filePath, NSError *error))downloadCompletionHandler;

//取消所有任务
- (void)cancelAllTask;
//取消当前任务
- (void)cancelCurrentTask;
//取消除当前任务外，所有的任务
- (void)cancelBeginAllTask;

@end