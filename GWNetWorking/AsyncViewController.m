//
//  TwoViewController.m
//  GWNetWorking
//
//  Created by gw on 2019/3/3.
//  Copyright © 2019 gw. All rights reserved.
//

#import "AsyncViewController.h"
#import "GWNetWorkingTools/GWNetWorking.h"
@interface AsyncViewController ()

@end

@implementation AsyncViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self request1];
    [self request2];
    [self request3];
    [self request4];
    
    [GWNetWorking GWAsyncQueueNotification:^{
        NSLog(@"------------5");
    }];
    
}

- (void)request1{
    [GWNetWorking GWAsyncQueueDownloadFileWithURLString:@"http://pic27.nipic.com/20130329/890845_115317964000_2.jpg" WithParam:nil withMethod:GET_GW downloadFileProgress:^(NSProgress *downloadProgress) {
        
    } setupFilePath:^NSURL *(NSURL *targetPath, NSURLResponse *response) {
        NSString *cachesPath = [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) lastObject];
        NSString *path = [cachesPath stringByAppendingPathComponent:response.suggestedFilename];
        return [NSURL fileURLWithPath:path];
    } downloadCompletionHandler:^(NSURL *filePath, NSError *error) {
        NSLog(@"------------1");
    }];
}

- (void)request2{
    [GWNetWorking GWAsyncQueueDownloadFileWithURLString:@"http://pic27.nipic.com/20130329/890845_115317964000_2.jpg" WithParam:nil withMethod:GET_GW downloadFileProgress:^(NSProgress *downloadProgress) {
        
    } setupFilePath:^NSURL *(NSURL *targetPath, NSURLResponse *response) {
        NSString *cachesPath = [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) lastObject];
        NSString *path = [cachesPath stringByAppendingPathComponent:response.suggestedFilename];
        return [NSURL fileURLWithPath:path];
    } downloadCompletionHandler:^(NSURL *filePath, NSError *error) {
        NSLog(@"------------2");
    }];
}

- (void)request3{
    NSDictionary *paramDict = @{
                                @"username":@"520it",
                                @"pwd":@"520it",
                                @"type":@"JSON"
                                };
    [GWNetWorking GWAsyncQueueRequest:@"http://120.25.226.186:32812/login" WithParam:paramDict withMethod:GET_GW success:^(id result, NSURLResponse *response) {
        
        NSLog(@"------------3");
    } failure:^(NSError *error) {
        
        NSLog(@"------------3");
    }];
    
}

- (void)request4{
    NSDictionary *paramDict = @{
                                @"username":@"520it",
                                @"pwd":@"520it",
                                @"type":@"JSON"
                                };
    [GWNetWorking GWAsyncQueueRequest:@"http://120.25.226.186:32812/login" WithParam:paramDict withMethod:GET_GW uploadFileProgress:^(NSProgress *uploadProgress) {
        
    } success:^(id result, NSURLResponse *response) {
        NSLog(@"------------4");
    } failure:^(NSError *error) {
        NSLog(@"------------4");
    }];

}

- (void)dealloc{
    NSLog(@"AsyncVC");
}

@end
