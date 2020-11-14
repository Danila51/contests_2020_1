
struct IOWrapper final{
public:
	handle_t handle;
	IOWrapper(handle_t handle): handle(handle){}

	IOWrapper() = delete;
	IOWrapper(IOWrapper const &src) = delete;
	IOWrapper& operator=(IOWrapper const &src) = delete;

	~IOWrapper() {
		if (handle != kNullHandle) {
			raw_close(handle);
		}
	}

	IOWrapper(IOWrapper&& src) {
		handle = src.handle;
		src.handle = kNullHandle;
	}

	IOWrapper& operator= (IOWrapper &&src) {
		handle = src.handle;
		src.handle = kNullHandle;
		return *this;
	}

	void Write(const std::string& a) {
		raw_write(handle, a);
	}
};
