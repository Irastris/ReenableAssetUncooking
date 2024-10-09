# ReenableAssetUncooking
ReenableAssetUncooking is an in-memory patch for the Unreal Editor supporting all versions of UE5 to date which re-enables asset uncooking via duplication. Utilizes patching methods by [@thethiny](https://github.com/thethiny) and [@ermaccer](https://github.com/ermaccer).

### Disclaimer:
Usage of ReenableAssetUncooking is entirely at the risk of the end user. No warranty is provided and ReenableAssetUncooking's contributors can not be held responsible for any potential damages. **YOU HAVE BEEN WARNED!**

### Instructions:
Download the compiled DLL from the [latest release](https://github.com/Irastris/ReenableAssetUncooking/releases/latest), or clone the repository and compile the solution in Visual Studio 2022. To utilize, the DLL should be injected into an open UnrealEditor process with any capable program, such as [Extreme Injector](https://github.com/master131/ExtremeInjector).

### Why?
Uncooking assets can at times be vital to Unreal modding projects. On 4.27 and earlier, it was possible to do so by adding the cooked asset to your project and duplicating it, which would recombine the cooked uasset/uexp into an uncooked uasset, at which point you could make your desired alterations. Epic Games patched the ability to so starting from UE5.0 by checking that the asset is not cooked before duplication occurs. ReenableAssetUncooking restores the <= 4.27 behavior by patching out that check from the single asset duplication function. Duplication of multiple assets at once is not yet patched.
