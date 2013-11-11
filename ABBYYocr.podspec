Pod::Spec.new do |s|
  s.name         = "ABBYYocr"
  s.version      = "0.0.4"
  s.summary      = "A native iOS API for ABBYY's ocr technology'"
  s.license      = "Contact ABBYY"
  s.author       = { "Mahmoud Abounassif" => "mahmoud.abounassif@gmail.com" }
  s.source_files = "*.{h,m}", "iPhone/**/*.{h,m}", "iPhoneSimulator/**/*.{h,m}"
  s.ios.vendored_library = "libAbbyyMsdk.a"
  s.source = {:git => 'https://github.com/mabounassif/ABBYYocr.git', :tag => 'v0.0.4'}
  s.homepage = "www.mahmoud.ca"
end
