
import Cocoa

func _mlx_bridge<T : AnyObject>(obj : T) -> UnsafeRawPointer {
    return UnsafeRawPointer(Unmanaged.passUnretained(obj).toOpaque())
}

func _mlx_bridge_retained<T : AnyObject>(obj : T) -> UnsafeRawPointer {
    return UnsafeRawPointer(Unmanaged.passRetained(obj).toOpaque())
}

func _mlx_bridge<T : AnyObject>(ptr : UnsafeRawPointer) -> T {
    return Unmanaged<T>.fromOpaque(ptr).takeUnretainedValue()
}

func _mlx_bridge_transfer<T : AnyObject>(ptr : UnsafeRawPointer) -> T {
    return Unmanaged<T>.fromOpaque(ptr).takeRetainedValue()
}


let MLX_SYNC_IMAGE_WRITABLE = Int32(1)
let MLX_SYNC_WIN_FLUSH_CMD = Int32(2)
let MLX_SYNC_WIN_CMD_COMPLETED = Int32(3)



/// C decl


@_cdecl("mlx_get_color_value")
public func mlx_get_color_value(_ mlxptr:UnsafeRawPointer, _ color:UInt32) -> UInt32
{
    return color
}

@_cdecl("mlx_get_screen_size")
public func mlx_get_screen_size_swift(_ mlxptr:UnsafeRawPointer, _ sizex:UnsafeMutablePointer<Int32>, _ sizey:UnsafeMutablePointer<Int32>) -> Int32
{
	/// let mlx:MlxMain = _mlx_bridge(ptr:mlxptr)
	sizex.pointee = Int32(NSScreen.main!.frame.size.width)
	sizey.pointee = Int32(NSScreen.main!.frame.size.height)
	return Int32(0)
}


@_cdecl("mlx_mouse_hide")
public func mlx_mouse_hide_swift() -> Int32
{
  NSCursor.hide()
  return Int32(0)
}

@_cdecl("mlx_mouse_show")
public func mlx_mouse_show_swift() -> Int32
{
  NSCursor.unhide()
  return Int32(0)
}

