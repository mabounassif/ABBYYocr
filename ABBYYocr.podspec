Pod::Spec.new do |s|
  s.name            = "ABBYYocr"
  s.version         = "0.0.1"
  s.summary         = "A native iOS API for ABBYY's ocr technology'"
  s.license         = "Contact ABBYY"
  s.author          = { "Mahmoud Abounassif" => "mahmoud.abounassif@gmail.com" }
  s.source          = { :git => 'git@github.com:mabounassif/ABBYYocr.git', :tag => s.version.to_s }

  s.source_files    = '*.h'
  s.preserve_paths = 'ABBYYocr.a'
  s.requires_arc    = true

  s.library         = 'ABBYYocr'
  s.xcconfig = { 'LIBRARY_SEARCH_PATHS' => "$(PODS_ROOT)/ABBYYocr",
                    'OTHER_LINKER_FLAGS' => "$(PODS_ROOT)/ABBYYocr/ABBYYocr.a"}
end
