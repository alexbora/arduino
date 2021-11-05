call plug#begin('~/.vim/plugged')
Plug 'morhetz/gruvbox' 
Plug 'junegunn/goyo.vim'
Plug 'neoclide/coc.nvim', {'branch': 'release'}
Plug 'honza/vim-snippets'
"Plug 'tpope/vim-fugitive'
Plug 'drmikehenry/vim-headerguard'
Plug 'tibabit/vim-templates'
Plug 'neoclide/vim-easygit'

call plug#end()
set bg=dark


set encoding=utf-8

" TextEdit might fail if hidden is not set.
set hidden

" Some servers have issues with backup files, see #649.
set nobackup
set nowritebackup

" Give more space for displaying messages.
set cmdheight=2

" Having longer updatetime (default is 4000 ms = 4 s) leads to noticeable
" delays and poor user experience.
set updatetime=300

" Don't pass messages to |ins-completion-menu|.
set shortmess+=c

" Always show the signcolumn, otherwise it would shift the text each time
" diagnostics appear/become resolved.
if has("nvim-0.5.0") || has("patch-8.1.1564")
  " Recently vim can merge signcolumn and number column into one
  set signcolumn=number
else
  set signcolumn=yes
endif


" Add `:Format` command to format current buffer.
command! -nargs=0 Format :call CocAction('format')



"set statusline^=%{coc#status()}%{get(b:,'coc_current_function','')}

"let g:clang_format#auto_format=1


function FormatBuffer()
   if &modified && !empty(findfile('.clang-format', expand('%:p:h') . ';'))
     let cursor_pos = getpos('.')
     :%!clang-format
     call setpos('.', cursor_pos)
   endif
 endfunction

"autocmd BufWritePre *.h,*.hpp,*.c,*.cpp,*.vert,*.frag :call FormatBuffer()
autocmd BufWritePre *.h,*.hpp,*.c,*.cpp,*.vert,*.frag :Format
let g:clang_complete_macros = 1
inoremap <silent><expr> <cr> pumvisible() ? coc#_select_confirm()
                              \: "\<C-g>u\<CR>\<c-r>=coc#on_enter()\<CR>"

set backspace=indent,eol,start

nnoremap <leader>g :Goyo<CR>

autocmd BufWinLeave *.* mkview
autocmd BufWinEnter *.* silent loadview

set makeprg=gcc-11\ -ggdb\ -std=gnu2x\ -o\ %<\ %\ -lpthread\ -lwebsockets\ -lssl\ -lcrypto\ -lcurl\ -ljson-c\ -mavx\ -w\ -fstrict-aliasing\ -O3
"set makeprg=gcc-11\ -o\ %:p:r\ %:p\ -std=c99\ -lpthread
"set makeprg=clang\ -ggdb\ -std=gnu99\ -o\ %<\ %\ -lpthread\ -lwebsockets\ -lssl\ -lcrypto\ -lcurl\ -ljson-c\ -mavx\ -Weverything\ -fstrict-aliasing\ -O3

set t_Co=256
colo gruvbox

"  if has("autocmd")
 "     augroup templates_
  "      autocmd BufNewFile *.cpp 0r ~/temp.cpp
   " 	autocmd BufNewFile *.c 0r ~/temp.c
    "  augroup END
   " endif

"let g:C_SourceCodeExtensions  = 'h cc cp cxx cpp CPP c++ C i ii'

 
"  if has("autocmd")
 "     augroup templates_
  "  	autocmd BufNewFile *.h call HeaderguardAdd()
      "augroup END
 "   endif

"nnoremap <space>e :CocCommand explorer<CR>
"let g:easygit_enable_command = 1
"autocmd BufNewFile,BufRead /tmp/mutt* set noautoindent filetype=mail wm=0 tw=78 nonumber digraph nolist
"autocmd BufNewFile,BufRead ~/tmp/mutt* set noautoindent filetype=mail wm=0 tw=78 nonumber digraph nolist


set undodir=~/tmp/undo
set undofile " Maintain undo history between sessions
set hidden
" set noswapfile
"autocmd bufenter  ~/tmp/* :set noswapfile
"set backupdir=/var/tmp,/tmp
"set directory=/var/tmp,/tmp

set nomodeline
set lazyredraw

set textwidth=200
nmap <silent> gd <Plug>(coc-definition)

