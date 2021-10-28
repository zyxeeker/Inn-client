<template>
    <div style="padding-left: 24px;position: relative;">
        <div style="display: flex;align-items: center;">
            <n-avatar
                :style="{marginRight:'10px',marginTop:'10px'}"
                src="https://07akioni.oss-cn-beijing.aliyuncs.com/07akioni.jpeg"/>
            <n-h4>
                {{ user }}
            </n-h4>
        </div>
        <n-space justify="start">
            <n-p :style="{paddingRight:'30px'}">
                {{ content }}
            </n-p>
        </n-space>
    </div>
</template>

<script>
export default {
    name: "Content",
    props: ['user', 'content']
}
</script>

<style scoped>

</style>
