// swift-tools-version: 5.6
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "libSvtAv1Enc",
    platforms: [.iOS(.v11), .macOS(.v12), .macCatalyst(.v14)],
    products: [
        // Products define the executables and libraries a package produces, and make them visible to other packages.
        .library(
            name: "libSvtAv1Enc",
            targets: ["libSvtAv1Enc"]),
    ],
    dependencies: [
        // Dependencies declare other packages that this package depends on.
        // .package(url: /* package url */, from: "1.0.0"),
    ],
    targets: [
        .binaryTarget(
            name: "libSvtAv1Enc",
            path: "Sources/libSvtAv1Enc.xcframework")
    ]
)
