# GenuinSDK

Check the documentation [here](https://resources.begenuin.com/developers/sdk-docs/ios_sdk_2.0){:target="_blank"}

## Cloning

This repository stores Pangle's `PAGAdSDK` binaries in [Git LFS](https://git-lfs.com)
— the simulator slice is 168 MB, past GitHub's 100 MB file limit. Install
git-lfs **before** cloning:

```bash
brew install git-lfs
git lfs install
```

If you cloned without it, the two `PAGAdSDK` files arrive as ~130-byte text
pointers instead of the real libraries and the build fails to link Pangle.
Fix an existing clone with:

```bash
git lfs install
git lfs pull
```

## Author 

Genuin Dev, development@begenuin.com
