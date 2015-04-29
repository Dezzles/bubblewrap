if PsyProjectExternalLib( "physfs", "C++" ) then
	configuration "*"
		kind ( EXTERNAL_PROJECT_KIND )
		includedirs {
			"physfs",
		}
		files {
			"physfs/physfs_byteorder.c",
			"physfs/physfs_unicode.c",
			"physfs/platform/os2.c",
			"physfs/platform/pocketpc.c",
			"physfs/platform/posix.c",
			"physfs/platform/unix.c",
			"physfs/platform/macosx.c",
			"physfs/platform/windows.c",
			"physfs/archivers/dir.c",
			"physfs/archivers/grp.c",
			"physfs/archivers/hog.c",
			"physfs/archivers/lzma.c",
			"physfs/archivers/mvl.c",
			"physfs/archivers/qpak.c",
			"physfs/archivers/wad.c",
			"physfs/archivers/zip.c",
			"physfs/lzma/C/7zCrc.c",
			"physfs/lzma/C/Archive/7z/7zBuffer.c",
			"physfs/lzma/C/Archive/7z/7zDecode.c",
			"physfs/lzma/C/Archive/7z/7zExtract.c",
			"physfs/lzma/C/Archive/7z/7zHeader.c",
			"physfs/lzma/C/Archive/7z/7zIn.c",
			"physfs/lzma/C/Archive/7z/7zItem.c",
			"physfs/lzma/C/Archive/7z/7zMethodID.c",
			"physfs/lzma/C/Compress/Branch/BranchX86.c",
			"physfs/lzma/C/Compress/Branch/BranchX86_2.c",
			"physfs/lzma/C/Compress/Lzma/LzmaDecode.c",
			"physfs/zlib123/adler32.c",
			"physfs/zlib123/compress.c",
			"physfs/zlib123/crc32.c",
			"physfs/zlib123/deflate.c",
			"physfs/zlib123/gzio.c",
			"physfs/zlib123/infback.c",
			"physfs/zlib123/inffast.c",
			"physfs/zlib123/inflate.c",
			"physfs/zlib123/inftrees.c",
			"physfs/zlib123/trees.c",
			"physfs/zlib123/uncompr.c",
			"physfs/zlib123/zutil.c"
		}
end
