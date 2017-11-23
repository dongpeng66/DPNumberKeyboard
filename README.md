# DPNumberKeyboard数字键盘
# 使用方法

```
    导入文件和图片
    #import "DPNumberKeyboard.h"并实现     DPNumberKeyboardDelegate代理

    
    DPNumberKeyboard *keyboard = [[DPNumberKeyboard alloc] initWithFrame:CGRectZero];
    keyboard.allowsDecimalPoint =  YES;
    keyboard.delegate = self;
    
    UITextField *textField = [[UITextField alloc] initWithFrame:CGRectMake(100, 100, 200, 40)];
    textField.textColor=[UIColor blackColor];
    textField.inputView = keyboard;
    textField.placeholder = @"请输入金额";
    textField.font = [UIFont systemFontOfSize:24.0f];
    
    [self.view addSubview:textField];
```
# 可以选择实现以下的代理
```
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
   
```

# 效果

![DPNumberKeyboard](https://github.com/dongpeng66/DPNumberKeyboard/blob/master/%20Screen.png)
