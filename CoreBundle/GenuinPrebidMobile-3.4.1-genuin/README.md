# GenuinPrebidMobile — PrebidMobile 3.4.1 (Genuin fork, renamed module)

Vendored by `GenuinCore.podspec` (`vendored_frameworks`). Built from
`genuininc/prebid-mobile-ios`, branch `genuin/release-sdk-2.1.11-module-rename` (on top of
`feature/audio-ad-support` @ `1b1a1f46` merged with upstream `master`, 3.4.1 `389f2c33`), which adds the
`BannerView` video controls (pause / resume / mute / skip / click-through,
playback time, duration, skip offset) the feed cells use.

- `GenuinPrebidMobile.xcframework`: the `Lib-PrebidMobile` scheme archived with the
  flags in the fork's `scripts/buildPrebidMobile.sh` (Release, device arm64,
  simulator arm64 + x86_64, `BUILD_LIBRARY_FOR_DISTRIBUTION=YES`).
- `OMSDK_Prebidorg.xcframework`: copied from the fork's `Frameworks/`; byte-identical to
  upstream 3.3.4–3.4.1. GenuinPrebidMobile links it dynamically. CocoaPods vendors it; the
  Swift package takes it from `prebid-mobile-ios` instead, so a host that also uses stock Prebid
  embeds one copy.

## Why the module is renamed (since SDK 2.1.11)

Host apps (iHeartRadio) also ship stock `prebid-mobile-ios`. Under the stock name SwiftPM refuses
the graph ("multiple packages declare targets with a conflicting name: 'PrebidMobile'") and the
ObjC runtime sees duplicate classes. The rename branch changes, and nothing else:

- framework target: `PRODUCT_NAME` / `PRODUCT_MODULE_NAME` = `GenuinPrebidMobile`,
  `PRODUCT_BUNDLE_IDENTIFIER` = `org.prebid.mobile.genuin`, modulemap `framework module GenuinPrebidMobile`;
- every explicit ObjC runtime name: `@objc(PB…)` / `@objc(PBM…)` → `@objc(GenuinPB…)`, and the
  ObjC-visible category methods on `UIView` / `UIWindow` get a `genuin` selector prefix, so they
  can't replace stock Prebid's methods.

Check after a rebuild: `nm -gU GenuinPrebidMobile | grep '_OBJC_CLASS_\$_' | grep -v __Tt | grep -v Genuin`
must print nothing.

## Interface patch (redo after every rebuild)

The Swift interface printer turns the source's
`@objc public protocol PrebidMobileDisplayViewProtocol where Self: UIView`
into `... : UIKit.UIView`, which fails to import ("inheritance from
non-protocol type 'UIView'"). Upstream's podspec hides this with
`-no-verify-emitted-module-interface`. After rebuilding, run in this folder:

```sh
grep -rl "protocol PrebidMobileDisplayViewProtocol : UIKit.UIView {" GenuinPrebidMobile.xcframework \
  | xargs sed -i '' 's/protocol PrebidMobileDisplayViewProtocol : UIKit\.UIView {/protocol PrebidMobileDisplayViewProtocol where Self : UIKit.UIView {/'
```
