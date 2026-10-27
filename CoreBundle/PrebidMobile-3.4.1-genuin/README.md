# PrebidMobile 3.4.1 (Genuin fork)

Vendored by `GenuinCore.podspec` (`vendored_frameworks`). Built from
`genuininc/prebid-mobile-ios`, branch `feature/audio-ad-support` @ `1b1a1f46` merged with
upstream `master` (3.4.1, `389f2c33`), which adds the
`BannerView` video controls (pause / resume / mute / skip / click-through,
playback time, duration, skip offset) the feed cells use.

- `PrebidMobile.xcframework`: the `Lib-PrebidMobile` scheme archived with the
  flags in the fork's `scripts/buildPrebidMobile.sh` (Release, device arm64,
  simulator arm64 + x86_64, `BUILD_LIBRARY_FOR_DISTRIBUTION=YES`).
- `OMSDK_Prebidorg.xcframework`: copied from the fork's `Frameworks/`.
  PrebidMobile links it dynamically.

## Interface patch (redo after every rebuild)

The Swift interface printer turns the source's
`@objc public protocol PrebidMobileDisplayViewProtocol where Self: UIView`
into `... : UIKit.UIView`, which fails to import ("inheritance from
non-protocol type 'UIView'"). Upstream's podspec hides this with
`-no-verify-emitted-module-interface`. After rebuilding, run in this folder:

```sh
grep -rl "protocol PrebidMobileDisplayViewProtocol : UIKit.UIView {" PrebidMobile.xcframework \
  | xargs sed -i '' 's/protocol PrebidMobileDisplayViewProtocol : UIKit\.UIView {/protocol PrebidMobileDisplayViewProtocol where Self : UIKit.UIView {/'
```
