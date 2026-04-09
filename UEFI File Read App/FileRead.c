#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Protocol/SimpleFileSystem.h>

EFI_STATUS
EFIAPI
UefiMain (
  IN EFI_HANDLE ImageHandle,
  IN EFI_SYSTEM_TABLE *SystemTable
)
{
  EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *Fs;
  EFI_FILE_PROTOCOL *Root, *File;
  CHAR16 Buffer[128];
  UINTN Size = sizeof(Buffer);

  gBS->LocateProtocol(&gEfiSimpleFileSystemProtocolGuid, NULL, (VOID**)&Fs);
  Fs->OpenVolume(Fs, &Root);
  Root->Open(Root, &File, L"test.txt", EFI_FILE_MODE_READ, 0);

  File->Read(File, &Size, Buffer);
  Print(L"File Content: %s\n", Buffer);

  File->Close(File);
  Root->Close(Root);
  return EFI_SUCCESS;
}
