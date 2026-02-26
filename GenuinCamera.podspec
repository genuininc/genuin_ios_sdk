#
#  Be sure to run `pod spec lint GenuinCamera.podspec' to ensure this is a
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

  spec.name         = "GenuinCamera"
  spec.version      = GENUIN_SDK_VERSION
  spec.summary      = "GenuinSDK is an SDK that consist feeds for which user has shown interest."
  spec.description  = "This is a home sdk of Genuin. GenuinSDK is an SDK that consist feeds for which user has shown interest."
  spec.homepage     = "https://github.com/genuininc/genuin_ios_sdk.git"
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

  spec.source       = { :git => "https://github.com/genuininc/genuin_ios_sdk.git", :tag => "#{spec.version}" }


  spec.dependency 'Giphy', '~> 2.1.22'
  spec.dependency 'GenuinCore', "= #{spec.version}"
  spec.dependency 'GenuinUI', "= #{spec.version}"

  spec.vendored_frameworks = "CameraBundle/GenuinCamera/GenuinCamera.xcframework", "CameraBundle/ffmpeg-kit-min-gpl-6.0-ios-xcframework/libswscale.xcframework", "CameraBundle/ffmpeg-kit-min-gpl-6.0-ios-xcframework/libswresample.xcframework", "CameraBundle/ffmpeg-kit-min-gpl-6.0-ios-xcframework/libavutil.xcframework", "CameraBundle/ffmpeg-kit-min-gpl-6.0-ios-xcframework/libavformat.xcframework", "CameraBundle/ffmpeg-kit-min-gpl-6.0-ios-xcframework/libavfilter.xcframework", "CameraBundle/ffmpeg-kit-min-gpl-6.0-ios-xcframework/libavdevice.xcframework", "CameraBundle/ffmpeg-kit-min-gpl-6.0-ios-xcframework/libavcodec.xcframework", "CameraBundle/ffmpeg-kit-min-gpl-6.0-ios-xcframework/ffmpegkit.xcframework"
end
