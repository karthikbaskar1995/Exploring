#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Protocol/PciIo.h>

EFI_STATUS
EFIAPI
UefiMain (
  IN EFI_HANDLE ImageHandle,
  IN EFI_SYSTEM_TABLE *SystemTable
)
{
  EFI_STATUS Status;
  EFI_HANDLE *HandleBuffer;
  UINTN HandleCount;
  UINTN Index;
  EFI_PCI_IO_PROTOCOL *PciIo;
  UINTN Segment, Bus, Device, Function;
  UINT32 PciId;

  Status = gBS->LocateHandleBuffer(
                  ByProtocol,
                  &gEfiPciIoProtocolGuid,
                  NULL,
                  &HandleCount,
                  &HandleBuffer
                  );

  if (EFI_ERROR(Status)) {
    Print(L"No PCI devices found\n");
    return Status;
  }

  Print(L"PCI Devices Found: %d\n\n", HandleCount);

  for (Index = 0; Index < HandleCount; Index++) {

    Status = gBS->HandleProtocol(
                    HandleBuffer[Index],
                    &gEfiPciIoProtocolGuid,
                    (VOID **)&PciIo
                    );

    if (EFI_ERROR(Status)) {
      continue;
    }

    PciIo->GetLocation(PciIo, &Segment, &Bus, &Device, &Function);
    PciIo->Pci.Read(PciIo, EfiPciIoWidthUint32, 0x00, 1, &PciId);

    Print(L"Bus %02x Dev %02x Func %02x | Vendor ID: %04x Device ID: %04x\n",
          Bus,
          Device,
          Function,
          (UINT16)(PciId & 0xFFFF),
          (UINT16)((PciId >> 16) & 0xFFFF));
  }

  return EFI_SUCCESS;
}
