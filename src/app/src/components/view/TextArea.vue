<template>
    <div style="display: flex;margin:10px">
        <n-input
            ref="input"
            type="textarea"
            placeholder="自动调整尺寸"
            :autosize="{minRows: 1}"
            @keyup.enter="SendMsg"
        >
            <template #prefix>
                <n-button size="large" text>
                    <n-icon>
                        <AddCircle32Regular/>
                    </n-icon>
                </n-button>
            </template>
            <template #suffix>
                <div style="height:100%;display: flex;flex-direction: row;align-items: flex-end;margin-bottom:20px; ">
                    <n-button size="large" text>
                        <n-icon>
                            <arrow-enter-left20-regular/>
                        </n-icon>
                    </n-button>
                </div>
            </template>
        </n-input>
    </div>
</template>

<script>
import {ArrowEnterLeft20Regular, AddCircle32Regular} from '@vicons/fluent'
import {defineComponent} from 'vue'

export default defineComponent({
    name: "TextArea",
    components: {
        ArrowEnterLeft20Regular,
        AddCircle32Regular
    },
    methods: {
        SendMsg() {
            this.$emit('input-msg', this.$refs.input.mergedValue)
        }
    }
})
</script>

<style scoped>

</style>
