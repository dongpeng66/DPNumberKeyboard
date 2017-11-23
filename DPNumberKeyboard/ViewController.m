//
//  ViewController.m
//  DPNumberKeyboard
//
//  Created by dp on 17/3/31.
//  Copyright © 2017年 dp. All rights reserved.
//

#import "ViewController.h"
#import "DPNumberKeyboard.h"
@interface ViewController ()<DPNumberKeyboardDelegate>

@property (strong, nonatomic) UITextField *textField;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    self.view.backgroundColor = [UIColor whiteColor];
    
    DPNumberKeyboard *keyboard = [[DPNumberKeyboard alloc] initWithFrame:CGRectZero];
    keyboard.allowsDecimalPoint =  YES;
    keyboard.delegate = self;
    
    UITextField *textField = [[UITextField alloc] initWithFrame:CGRectMake(100, 100, 200, 40)];
    textField.textColor=[UIColor blackColor];
    textField.inputView = keyboard;
    textField.placeholder = @"请输入金额";
    textField.font = [UIFont systemFontOfSize:24.0f];
//    textField.contentVerticalAlignment = UIControlContentVerticalAlignmentTop;
    
    self.textField = textField;
    
    [self.view addSubview:textField];
}
#pragma mark - DPNumberKeyboardDelegate的代理

- (BOOL)numberKeyboardShouldReturn:(DPNumberKeyboard *)numberKeyboard
{
    // Do something with the done key if neeed. Return YES to dismiss the keyboard.
    return YES;
}
-(void)numberKeyboardTextString:(DPNumberKeyboard *)numberKeyboard withTextString:(NSString *)text{
    //可以监听输入的内容
    NSLog(@"--------%@",text);
}

#pragma mark - View events.

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    
    [self.textField becomeFirstResponder];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
