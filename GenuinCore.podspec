#
#  Be sure to run `pod spec lint GenuinSDK.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

require_relative 'GenuinSDKVersion'

Pod::Spec.new do |spec|

  # ―――  Spec Metadata  ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  These will help people to find your library, and whilst it
  #  can feel like a chore to fill in it's definitely to your advantage. The
  #  summary should be tweet-length, and the description more in depth.
  #

  spec.name         = "GenuinCore"
  spec.version      = GENUIN_SDK_VERSION
  spec.summary      = "GenuinSDK is an SDK that consist feeds for which user has shown interest."
  spec.description  = "This is a home sdk of Genuin. GenuinSDK is an SDK that consist feeds for which user has shown interest."
  spec.homepage     = "https://bitbucket.org/genuindev/genuin_ios_sdk.git"
  spec.license      = "MIT"
  spec.author       = { "Genuin Dev" => "development@begenuin.com" }

  spec.platform     = :ios
  spec.platform     = :ios, "13.0"
  spec.ios.deployment_target = "13.0"


  # ――― Source Location ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  Specify the location from where the source should be retrieved.
  #  Supports git, hg, bzr, svn and HTTP.
  #

  spec.source       = { :git => "https://bitbucket.org/genuindev/genuin_ios_sdk.git", :tag => "#{spec.version}" }


#  spec.dependency 'SDWebImage', '~> 5.21.3'
  spec.dependency 'lottie-ios', '~> 4.4.0'
  spec.dependency 'Hero', '~> 1.6.2'
  spec.dependency 'SkeletonView', '~> 1.30.4'
  spec.dependency 'CryptoSwift', '~> 1.8.1'
  spec.dependency 'SnapKit', '~> 5.7.1'
  spec.dependency 'EasyTipView', '~> 2.1'
  spec.dependency 'GoogleAds-IMA-iOS-SDK', '~> 3.27.4'
  spec.dependency 'MaterialComponents/ActivityIndicator', '~> 124.2.0'

  spec.vendored_frameworks = "CoreBundle/GenuinCore/GenuinCore.xcframework", "CoreBundle/TOCropViewController_2.6.1/TOCropViewController.xcframework",
      "CoreBundle/Rudder_1.31.0/MetricsReporter.xcframework",
      "CoreBundle/Rudder_1.31.0/RSCrashReporter.xcframework",
      "CoreBundle/Rudder_1.31.0/Rudder.xcframework",
      "CoreBundle/Rudder_1.31.0/RudderKit.xcframework"
end
