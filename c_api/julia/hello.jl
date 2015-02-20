argv = ["hello"]
ccall( (:main, "hello"), Int32, (Int32, Ptr{Ptr{UInt8}}), length(argv), argv)
