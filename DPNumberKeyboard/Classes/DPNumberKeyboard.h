//
//  DPNumberKeyboard.h
//  DPNumberKeyboard
//
//  Created by dp on 17/3/31.
//  Copyright © 2017年 dp. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for DPNumberKeyboard.
FOUNDATION_EXPORT double DPNumberKeyboardVersionNumber;

//! Project version string for DPNumberKeyboard.
FOUNDATION_EXPORT const unsigned char DPNumberKeyboardVersionString[];

@class DPNumberKeyboard;

/**
 *  The @c DPNumberKeyboardDelegate protocol defines the messages sent to a delegate object as part of the sequence of editing text. All of the methods of this protocol are optional.
 */
@protocol DPNumberKeyboardDelegate <NSObject>
@optional

/**
 *  Asks whether the specified text should be inserted.
 *
 *  @param numberKeyboard The keyboard instance proposing the text insertion.
 *  @param text           The proposed text to be inserted.
 *
 *  @return Returns	@c YES if the text should be inserted or @c NO if it should not.
 */
- (BOOL)numberKeyboard:(DPNumberKeyboard *)numberKeyboard shouldInsertText:(NSString *)text;

/**
 *  Asks the delegate if the keyboard should process the pressing of the return button.
 *
 *  @param numberKeyboard The keyboard whose return button was pressed.
 *
 *  @return Returns	@c YES if the keyboard should implement its default behavior for the return button; otherwise, @c NO.
 */
- (BOOL)numberKeyboardShouldReturn:(DPNumberKeyboard *)numberKeyboard;

/**
 *  Asks the delegate if the keyboard should remove the character just before the cursor.
 *
 *  @param numberKeyboard The keyboard whose return button was pressed.
 *
 *  @return Returns	@c YES if the keyboard should implement its default behavior for the delete backward button; otherwise, @c NO.
 */
- (BOOL)numberKeyboardShouldDeleteBackward:(DPNumberKeyboard *)numberKeyboard;
/**
 返回textFild输入的内容
 */
- (void)numberKeyboardTextString:(DPNumberKeyboard *)numberKeyboard withTextString:(NSString *)text;
@end

/**
 *  Specifies the style of a keyboard button.
 */
typedef NS_ENUM(NSUInteger, DPNumberKeyboardButtonStyle) {
    /**
     *  A white style button, such as those for the number keys.
     */
    DPNumberKeyboardButtonStyleWhite,
    
    /**
     *  A gray style button, such as the backspace key.
     */
    DPNumberKeyboardButtonStyleGray,
    
    /**
     *  A done style button, for example, a button that completes some task and returns to the previous view.
     */
    DPNumberKeyboardButtonStyleDone
};

/**
 *  A simple keyboard to use with numbers and, optionally, a decimal point.
 */
@interface DPNumberKeyboard : UIInputView

/**
 *  Initializes and returns a number keyboard view using the specified style information and locale.
 *
 *  An initialized view object or @c nil if the view could not be initialized.
 *
 *  @param frame          The frame rectangle for the view, measured in points. The origin of the frame is relative to the superview in which you plan to add it.
 *  @param inputViewStyle The style to use when altering the appearance of the view and its subviews. For a list of possible values, see @c UIInputViewStyle
 *  @param locale         An @c NSLocale object that specifies options (specifically the @c NSLocaleDecimalSeparator) used for the keyboard. Specify @c nil if you want to use the current locale.
 *
 *  @returns An initialized view object or @c nil if the view could not be initialized.
 */
- (instancetype)initWithFrame:(CGRect)frame inputViewStyle:(UIInputViewStyle)inputViewStyle locale:(NSLocale *)locale;

/**
 *  The receiver key input object. If @c nil the object at top of the responder chain is used.
 */
@property (weak, nonatomic) id <UIKeyInput> keyInput;

/**
 *  Delegate to change text insertion or return key behavior.
 */
@property (weak, nonatomic) id <DPNumberKeyboardDelegate> delegate;

/**
 *  Configures the special key with an image and an action block.
 *
 *  @param image   The image to display in the key.
 *  @param handler A handler block.
 */
- (void)configureSpecialKeyWithImage:(UIImage *)image actionHandler:(dispatch_block_t)handler;

/**
 *  Configures the special key with an image and a target-action.
 *
 *  @param image  The image to display in the key.
 *  @param target The target object—that is, the object to which the action message is sent.
 *  @param action A selector identifying an action message. It cannot be NULL.
 */
- (void)configureSpecialKeyWithImage:(UIImage *)image target:(id)target action:(SEL)action;

/**
 *  If @c YES, the decimal separator key will be displayed.
 *
 *  @note The default value of this property is @c NO.
 */
@property (assign, nonatomic) BOOL allowsDecimalPoint;

/**
 *  The visible title of the Return key.
 *
 *  @note The default visible title of the Return key is “Done”.
 */
@property (copy, nonatomic) NSString *returnKeyTitle;

/**
 *  The button style of the Return key.
 *
 *  @note The default value of this property is @c DPNumberKeyboardButtonStyleDone.
 */
@property (assign, nonatomic) DPNumberKeyboardButtonStyle returnKeyButtonStyle;

@end
