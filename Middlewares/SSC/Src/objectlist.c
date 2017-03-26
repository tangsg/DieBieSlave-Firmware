#include "objectlist.h"

static const char acName1000[] = "Device Type";
static const char acName1008[] = "Manufacturer Device Name";
static const char acName1009[] = "Manufacturer Hardware Version";
static const char acName100A[] = "Manufacturer Software Version";
static const char acName1018[] = "Identity Object";
static const char acName1018_01[] = "Vendor ID";
static const char acName1018_02[] = "Product Code";
static const char acName1018_03[] = "Revision Number";
static const char acName1018_04[] = "Serial Number";
static const char acNameMO[] = "Mapped object";
static const char acName1600[] = "Receive PDO mapping";
static const char acName1A00[] = "Transmit PDO mapping";
static const char acName1C00[] = "Sync Manager Communication type";
static const char acName1C00_01[] = "Communications type SM0";
static const char acName1C00_02[] = "Communications type SM1";
static const char acName1C00_03[] = "Communications type SM2";
static const char acName1C00_04[] = "Communications type SM3";
static const char acName1C10[] = "Sync Manager 0 PDO Assignment";
static const char acName1C11[] = "Sync Manager 1 PDO Assignment";
static const char acName1C12[] = "Sync Manager 2 PDO Assignment";
static const char acName1C13[] = "Sync Manager 3 PDO Assignment";
static const char acNameNOE[] = "Number of entries";
static const char acName6000[] = "Digital Inputs";

static const char acName6000_01[] = "JoyStickX";
static const char acName6000_02[] = "JoyStickY";
static const char acName6000_03[] = "AcceleroMeterX";
static const char acName6000_04[] = "AcceleroMeterY";
static const char acName6000_05[] = "AcceleroMeterZ";
static const char acName6000_06[] = "ButtonC";
static const char acName6000_07[] = "ButtonZ";
static const char acName6000_08[] = "NunChuckDataValid";

static const char acName7000[] = "Digital outputs";
static const char acName7000_01[] = "LED";
static const char acName7100[] = "Parameters";
static const char acName8001[] = "Slave commands";

static char ac1008_00[] = "DieBieSlave - NunChuck";
static char ac1009_00[] = "0.1";
static char ac100A_00[] = "0.3";

const _objd SDO1000[] =
{ {0x00, DTYPE_UNSIGNED32, 32, ATYPE_RO, &acName1000[0], 0x00000001, NULL} };

const _objd SDO1008[] =
{ {0x00, DTYPE_VISIBLE_STRING, sizeof (ac1008_00) << 3, ATYPE_RO, &acName1008[0], 0, &ac1008_00[0]}
};

const _objd SDO1009[] =
{ {0x00, DTYPE_VISIBLE_STRING, sizeof (ac1009_00) << 3, ATYPE_RO, &acName1009[0], 0, &ac1009_00[0]}
};

const _objd SDO100A[] =
{ {0x00, DTYPE_VISIBLE_STRING, sizeof (ac100A_00) << 3, ATYPE_RO, &acName100A[0], 0, &ac100A_00[0]}
};

const _objd SDO1018[] =
{ {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, &acNameNOE[0], 0x04, NULL},
  {0x01, DTYPE_UNSIGNED32, 32, ATYPE_RO, &acName1018_01[0], 0x00000959, NULL},
  {0x02, DTYPE_UNSIGNED32, 32, ATYPE_RO, &acName1018_02[0], 0x12783456, NULL},
  {0x03, DTYPE_UNSIGNED32, 32, ATYPE_RO, &acName1018_03[0], 0x00000001, NULL},
  {0x04, DTYPE_UNSIGNED32, 32, ATYPE_RO, &acName1018_04[0], 0x00000000, NULL}
};

const _objd SDO1600[] =
{ {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, &acNameNOE[0], 0x02, NULL},
  {0x01, DTYPE_UNSIGNED32, 32, ATYPE_RO, &acNameMO[0], 0x70000101, NULL},
	{0x02, DTYPE_UNSIGNED32, 32, ATYPE_RO, &acNameMO[0], 0x00000007, NULL}
};

const _objd SDO1A00[] =
{ {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, &acNameNOE[0], 0x0B, NULL},
  {0x01, DTYPE_UNSIGNED32, 32, ATYPE_RO, &acNameMO[0], 0x60000108, NULL},
  {0x02, DTYPE_UNSIGNED32, 32, ATYPE_RO, &acNameMO[0], 0x60000208, NULL},
  {0x03, DTYPE_UNSIGNED32, 32, ATYPE_RO, &acNameMO[0], 0x60000310, NULL},
  {0x04, DTYPE_UNSIGNED32, 32, ATYPE_RO, &acNameMO[0], 0x60000410, NULL},
  {0x05, DTYPE_UNSIGNED32, 32, ATYPE_RO, &acNameMO[0], 0x60000510, NULL},
  {0x06, DTYPE_UNSIGNED32, 32, ATYPE_RO, &acNameMO[0], 0x60000601, NULL},
  {0x07, DTYPE_UNSIGNED32, 32, ATYPE_RO, &acNameMO[0], 0x00000007, NULL},	
  {0x08, DTYPE_UNSIGNED32, 32, ATYPE_RO, &acNameMO[0], 0x60000701, NULL},
  {0x09, DTYPE_UNSIGNED32, 32, ATYPE_RO, &acNameMO[0], 0x00000007, NULL},
  {0x0A, DTYPE_UNSIGNED32, 32, ATYPE_RO, &acNameMO[0], 0x60000801, NULL},
  {0x0B, DTYPE_UNSIGNED32, 32, ATYPE_RO, &acNameMO[0], 0x00000007, NULL}
}; // PDO Items

const _objd SDO1C00[] =
{ {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, &acNameNOE[0], 0x04, NULL},
  {0x01, DTYPE_UNSIGNED8, 8, ATYPE_RO, &acName1C00_01[0], 0x01, NULL},
  {0x02, DTYPE_UNSIGNED8, 8, ATYPE_RO, &acName1C00_02[0], 0x02, NULL},
  {0x03, DTYPE_UNSIGNED8, 8, ATYPE_RO, &acName1C00_03[0], 0x03, NULL},
  {0x04, DTYPE_UNSIGNED8, 8, ATYPE_RO, &acName1C00_04[0], 0x04, NULL}
};

const _objd SDO1C10[] =
{ {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, &acName1C10[0], 0x00, NULL}
};

const _objd SDO1C11[] =
{ {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, &acName1C11[0], 0x00, NULL}
};

const _objd SDO1C12[] =
{ {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, &acNameNOE[0], 0x01, NULL},
  {0x01, DTYPE_UNSIGNED16, 16, ATYPE_RO, &acNameMO[0], 0x1600, NULL}
};

const _objd SDO1C13[] =
{ {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, &acNameNOE[0], 0x01, NULL},
  {0x01, DTYPE_UNSIGNED16, 16, ATYPE_RO, &acNameMO[0], 0x1A00, NULL}
};

const _objd SDO6000[] =
{ {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, &acNameNOE[0], 0x08, NULL},
  {0x01, DTYPE_INTEGER8, 8, ATYPE_RO, &acName6000_01[0], 0, &(middleSOESReadBuffer.joyStickX)},
  {0x02, DTYPE_INTEGER8, 8, ATYPE_RO, &acName6000_02[0], 0, &(middleSOESReadBuffer.joyStickY)},
  {0x03, DTYPE_INTEGER16, 16, ATYPE_RO, &acName6000_03[0], 0, (void *)&(middleSOESReadBuffer.AcceleroMeterX)},
  {0x04, DTYPE_INTEGER16, 16, ATYPE_RO, &acName6000_04[0], 0, (void *)&(middleSOESReadBuffer.AcceleroMeterY)},
  {0x05, DTYPE_INTEGER16, 16, ATYPE_RO, &acName6000_05[0], 0, (void *)&(middleSOESReadBuffer.AcceleroMeterZ)},
  {0x06, DTYPE_BOOLEAN, 1, ATYPE_RO, &acName6000_06[0], 0, &(middleSOESReadBuffer.buttonC)},
  {0x07, DTYPE_BOOLEAN, 1, ATYPE_RO, &acName6000_07[0], 0, &(middleSOESReadBuffer.buttonZ)},
  {0x08, DTYPE_BOOLEAN, 1, ATYPE_RO, &acName6000_08[0], 0, &(middleSOESReadBuffer.dataValid)}	
}; // SDO Mailbox items

const _objd SDO7000[] =
{ {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, &acNameNOE[0], 0x01, NULL},
  {0x01, DTYPE_BOOLEAN, 1, ATYPE_RW, &acName7000_01[0], 0, &(middleSOESWriteBuffer.LED)}
};

const _objd SDO7100[] =
{ {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, &acNameNOE[0], 0x00, NULL}
};

const _objd SDO8001[] =
{ {0x00, DTYPE_UNSIGNED8, 8, ATYPE_RO, &acNameNOE[0], 0x00, NULL}
};

const _objectlist SDOobjects[] =
{ {0x1000, OTYPE_VAR, 0, 0, &acName1000[0], &SDO1000[0]},
  {0x1008, OTYPE_VAR, 0, 0, &acName1008[0], &SDO1008[0]},
  {0x1009, OTYPE_VAR, 0, 0, &acName1009[0], &SDO1009[0]},
  {0x100A, OTYPE_VAR, 0, 0, &acName100A[0], &SDO100A[0]},
  {0x1018, OTYPE_RECORD, 4, 0, &acName1018[0], &SDO1018[0]},
  {0x1600, OTYPE_RECORD, 0x02, 0, &acName1600[0], &SDO1600[0]},
  {0x1A00, OTYPE_RECORD, 0x0B, 0, &acName1A00[0], &SDO1A00[0]},
  {0x1C00, OTYPE_ARRAY, 4, 0, &acName1C00[0], &SDO1C00[0]},
  {0x1C10, OTYPE_ARRAY, 0, 0, &acName1C10[0], &SDO1C10[0]},
  {0x1C11, OTYPE_ARRAY, 0, 0, &acName1C11[0], &SDO1C11[0]},
  {0x1C12, OTYPE_ARRAY, 1, 0, &acName1C12[0], &SDO1C12[0]},
  {0x1C13, OTYPE_ARRAY, 1, 0, &acName1C13[0], &SDO1C13[0]},
  {0x6000, OTYPE_ARRAY, 0x08, 0, &acName6000[0], &SDO6000[0]},
  {0x7000, OTYPE_ARRAY, 0x01, 0, &acName7000[0], &SDO7000[0]},
  {0x7100, OTYPE_ARRAY, 0x00, 0, &acName7100[0], &SDO7100[0]},
  {0x8001, OTYPE_ARRAY, 0x00, 0, &acName8001[0], &SDO8001[0]},
  {0xffff, 0xff, 0xff, 0xff, NULL, NULL}
};
