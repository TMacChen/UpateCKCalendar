//
//  CGCalendarView.h
//  云传智联
//
//  Created by 陈刚 on 2017/4/19.
//  Copyright © 2017年 陈刚. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol CGCalendarDelegate;

@interface CGDateItem : NSObject

@property (nonatomic, strong) UIColor *backgroundColor;
@property (nonatomic, strong) UIColor *selectedBackgroundColor;
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong) UIColor *selectedTextColor;

@end

typedef enum {
    startSunday = 1,
    startMonday = 2,
} CGCalendarStartDay;

@interface CGCalendarView : UIView

- (instancetype)initWithStartDay:(CGCalendarStartDay)firstDay;
- (instancetype)initWithStartDay:(CGCalendarStartDay)firstDay frame:(CGRect)frame;

@property (nonatomic) CGCalendarStartDay calendarStartDay;
@property (nonatomic, strong) NSLocale *locale;

@property (nonatomic, readonly) NSArray *datesShowing;

@property (nonatomic) BOOL onlyShowCurrentMonth;
@property (nonatomic) BOOL adaptHeightToNumberOfWeeksInMonth;

@property (nonatomic, weak) id<CGCalendarDelegate> delegate;

// Theming
@property (nonatomic, strong) UIFont *titleFont;
@property (nonatomic, strong) UIColor *titleColor;
@property (nonatomic, strong) UIFont *dateOfWeekFont;
@property (nonatomic, strong) UIColor *dayOfWeekTextColor;
@property (nonatomic, strong) UIFont *dateFont;

- (void)setMonthButtonColor:(UIColor *)color;
- (void)setInnerBorderColor:(UIColor *)color;
- (void)setDayOfWeekBottomColor:(UIColor *)bottomColor topColor:(UIColor *)topColor;

- (void)selectDate:(NSDate *)date makeVisible:(BOOL)visible;
- (void)reloadData;
- (void)reloadDates:(NSArray *)dates;

// Helper methods for delegates, etc.
- (BOOL)date:(NSDate *)date1 isSameDayAsDate:(NSDate *)date2;
- (BOOL)dateIsInCurrentMonth:(NSDate *)date;

@end

@protocol CGCalendarDelegate <NSObject>

@optional
- (void)calendar:(CGCalendarView *)calendar configureDateItem:(CGDateItem *)dateItem forDate:(NSDate *)date;
- (BOOL)calendar:(CGCalendarView *)calendar willSelectDate:(NSDate *)date;
- (void)calendar:(CGCalendarView *)calendar didSelectDate:(NSDate *)date;
- (BOOL)calendar:(CGCalendarView *)calendar willDeselectDate:(NSDate *)date;
- (void)calendar:(CGCalendarView *)calendar didDeselectDate:(NSDate *)date;

- (BOOL)calendar:(CGCalendarView *)calendar willChangeToMonth:(NSDate *)date;
- (void)calendar:(CGCalendarView *)calendar didChangeToMonth:(NSDate *)date;

- (void)calendar:(CGCalendarView *)calendar didLayoutInRect:(CGRect)frame;

@end

