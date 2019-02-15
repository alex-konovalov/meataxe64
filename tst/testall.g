#
# meataxe64: meataxe64
#
# This file runs package tests. It is also referenced in the package
# metadata in PackageInfo.g.
#
LoadPackage( "meataxe64" );

TestDirectory([DirectoriesPackageLibrary( "meataxe64", "tst/testinstall" ),
DirectoriesPackageLibrary( "meataxe64", "tst/testfull" )],
  rec(exitGAP := true));

FORCE_QUIT_GAP(1); # if we ever get here, there was an error
