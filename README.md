# RemoveManifestFromDll

This application removes the manifest from a precompiled DLL.

Sometimes you need a certain DLL to have the manifest as an external file (to allow the user to add modifications or to install the DLL in WinSxS).

If the DLL is precompiled (for example, you downloaded or obtained it via vcpkg.exe) and it comes with the manifest embedded in the resources, the embedded manifest takes precedence over the external manifest.

With this tool, you can remove the manifest from the resource file.

The application is preconfigured to remove the US English manifest. If the resource you intend to remove is not in US English, you must modify and recompile the application.

To see the ID of the resource to delete you can open the DLL directly with Visual Studio and see the number that appears together with the resource RT_MANIFEST.

This application uses the following APIs:

* [BeginUpdateResourceA](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-beginupdateresourcea)
* [UpdateResource](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-updateresourcea)
* [EndUpdateResource](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-endupdateresourcea)

Example of use:

```cmd
RemoveManifestFromDll.exe zip.dll 2
```
