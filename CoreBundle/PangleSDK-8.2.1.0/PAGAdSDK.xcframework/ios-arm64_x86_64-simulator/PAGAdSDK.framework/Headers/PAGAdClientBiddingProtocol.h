//
//  PAGAdClientBiddingProtocol.h
//  Pangle Ads SDK
//
//  Copyright 2021 ByteDance Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol PAGAdClientBiddingProtocol <NSObject>

@optional

/// invoke this method when the bidding  succeeds (strongly recommended)
/// @param auctionBidToWin the seccond place bidder's price
- (void)win:(nullable NSNumber*)auctionBidToWin;

/// invoke this method when the bidding  fails (strongly recommended)
/// @param auctionPrice auction price
/// @param lossReason Reasons for failed bidding
/// @param winBidder Who won the bid
- (void)loss:(nullable NSNumber*)auctionPrice lossReason:(nullable NSString*)lossReason winBidder:(nullable NSString*)winBidder;

@end
