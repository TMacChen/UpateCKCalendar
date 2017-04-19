//
//  ViewController.m
//  NewCKCalendar
//
//  Created by 陈刚 on 2017/4/19.
//  Copyright © 2017年 陈刚. All rights reserved.
//

#import "ViewController.h"
#import "CGCalendarView.h"

@interface ViewController () <CGCalendarDelegate>

@property(nonatomic, strong) UIView *calendarView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    self.title = @"Calendar";
    
    UIBarButtonItem *rightItem = [[UIBarButtonItem alloc] initWithTitle:@"日历" style:UIBarButtonItemStylePlain target:self action:@selector(showCalendar)];
    self.navigationItem.rightBarButtonItem = rightItem;
}

- (UIView *)calendarView {
    if (!_calendarView) {
        UIView *calendarView = [[UIView alloc] initWithFrame:self.view.bounds];
        calendarView.backgroundColor = [UIColor colorWithRed:0 green:0 blue:0 alpha:0.5];
        UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(removeCalendar:)];
        [calendarView addGestureRecognizer:tap];
        
        CGCalendarView *calendar = [[CGCalendarView alloc] initWithStartDay:startSunday frame:CGRectMake(20, 140, CGRectGetWidth(calendarView.frame)-40, MIN(320, calendarView.frame.size.height-160))];
        calendar.delegate = self;
        calendar.onlyShowCurrentMonth = NO;
        calendar.adaptHeightToNumberOfWeeksInMonth = YES;
        [calendarView addSubview:calendar];
        
        _calendarView = calendarView;
    }
    return _calendarView;
}

- (void)removeCalendar:(UITapGestureRecognizer *)recognizer {
    [self.calendarView removeFromSuperview];
}

- (void)showCalendar {
    if (![self.view.subviews containsObject:self.calendarView]) {
        [self.view addSubview:self.calendarView];
    }
}

#pragma mark -CGCalendarDelegate
- (void)calendar:(CGCalendarView *)calendar didSelectDate:(NSDate *)date {
    NSLog(@"date: %@",date);
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
