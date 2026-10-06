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


  spec.dependency 'lottie-ios', '~> 4.6.0'
  spec.dependency 'Hero', '~> 1.6.2'
  spec.dependency 'SkeletonView', '~> 1.30.4'
  spec.dependency 'EasyTipView', '~> 2.1'
  spec.dependency 'GoogleAds-IMA-iOS-SDK', '~> 3.22.1'
  spec.dependency 'MaterialComponents/ActivityIndicator', '~> 124.2.0'
  spec.dependency 'XLPagerTabStrip', '~> 9.1.0'

  # PAGAdSDK (Pangle) is vendored below alongside GoogleMobileAds, so linking it
  # requires Pangle's own system dependencies. This mirrors the upstream
  # Ads-Global podspec in full: in this pod graph only zlib and libresolv are
  # actually missing, but a consumer with a smaller graph could need any of the
  # others, and system libs/frameworks cost nothing at runtime.
  spec.libraries = 'c++', 'c++abi', 'resolv', 'z', 'sqlite3', 'bz2', 'xml2', 'iconv'
  spec.frameworks = 'UIKit', 'WebKit', 'MediaPlayer', 'AdSupport', 'CoreMedia',
                    'AVFoundation', 'CoreTelephony', 'StoreKit', 'SystemConfiguration',
                    'MobileCoreServices', 'CoreMotion', 'Accelerate', 'AudioToolbox',
                    'JavaScriptCore', 'Security', 'CoreImage'
  spec.weak_frameworks = 'AppTrackingTransparency', 'CoreML', 'DeviceCheck'

  spec.vendored_frameworks = "CoreBundle/GenuinCore/GenuinCore.xcframework", "CoreBundle/libPhoneNumberiOS_0.9.15/libPhoneNumberiOS.xcframework", "CoreBundle/TOCropViewController_2.6.1/TOCropViewController.xcframework",
      "CoreBundle/Rudder_1.31.0/MetricsReporter.xcframework",
      "CoreBundle/Rudder_1.31.0/RSCrashReporter.xcframework",
      "CoreBundle/Rudder_1.31.0/Rudder.xcframework",
      "CoreBundle/Rudder_1.31.0/RudderKit.xcframework",
      "CoreBundle/GoogleMobileAdsSdkiOS-13.3.0/GoogleMobileAds.xcframework", "CoreBundle/GoogleMobileAdsSdkiOS-13.3.0/UserMessagingPlatform.xcframework",
      "CoreBundle/PangleSDK-8.2.1.0/PAGAdSDK.xcframework"

  # PAGAdSDK binaries are committed as Git LFS pointers (each slice is over
  # GitHub's 100 MB limit), so a plain `git clone` by CocoaPods gets ~130-byte
  # text files instead of Mach-O archives and the link fails. If either slice
  # is not Mach-O, replace the xcframework with Pangle's official 8.2.1.0 zip
  # (SHA-256 verified). Host apps do not need git-lfs. Not run for :path pods.
  pangle_dir = 'CoreBundle/PangleSDK-8.2.1.0'
  pangle_url = 'https://sf16-fe-tos-sg.i18n-pglstatp.com/obj/pangle-sdk-static-va/8.2.1.0/PAGAdSDK.xcframework.zip'
  pangle_sha256 = 'c03d7b5845d334f7e56fc007b4e557762154634cf1f6639876f9b69eeb0bf904'
  spec.prepare_command = <<-CMD
    set -e
    DIR="#{pangle_dir}"
    NEEDS_DOWNLOAD=0
    for BIN in "$DIR"/PAGAdSDK.xcframework/*/PAGAdSDK.framework/PAGAdSDK; do
      file -b "$BIN" | grep -q "Mach-O" || NEEDS_DOWNLOAD=1
    done
    if [ "$NEEDS_DOWNLOAD" = "1" ]; then
      curl -fsSL --retry 3 -o "$DIR/PAGAdSDK.xcframework.zip" "#{pangle_url}"
      echo "#{pangle_sha256}  $DIR/PAGAdSDK.xcframework.zip" | shasum -a 256 -c -
      rm -rf "$DIR/PAGAdSDK.xcframework"
      unzip -q -o "$DIR/PAGAdSDK.xcframework.zip" -d "$DIR"
      rm -f "$DIR/PAGAdSDK.xcframework.zip"
    fi
  CMD

end
